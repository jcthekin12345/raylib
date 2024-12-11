import random
import numpy as np
from dataclasses import dataclass
from typing import List, Dict, Tuple, Optional, Set
import math
from enum import Enum
from collections import defaultdict


class DisasterType(Enum):
	FIRE = "fire"
	FLOOD = "flood"
	DROUGHT = "drought"
	DISEASE = "disease"


class TerrainType(Enum):
	WATER = "water"
	PLAINS = "plains"
	FOREST = "forest"
	MOUNTAIN = "mountain"
	DESERT = "desert"
	SWAMP = "swamp"
	TUNDRA = "tundra"


class Species(Enum):
	PLANT = "plant"
	HERBIVORE = "herbivore"
	CARNIVORE = "carnivore"
	OMNIVORE = "omnivore"


@dataclass
class Disease:
	name: str
	infection_rate: float
	mortality_rate: float
	duration: int
	resistance_gene: str


class SocialGroup:
	def __init__(self, species: Species):
		self.members: Set['Organism'] = set()
		self.species = species
		self.leader: Optional['Organism'] = None
		self.territory_center: Tuple[float, float] = (0, 0)
		self.territory_radius: float = 20.0
	
	def update_territory(self):
		if self.members:
			x_coords = [m.position[0] for m in self.members]
			y_coords = [m.position[1] for m in self.members]
			self.territory_center = (np.mean(x_coords), np.mean(y_coords))
	
	def choose_leader(self):
		if self.members:
			self.leader = max(self.members, key=lambda x: x.genes['leadership'].value)


@dataclass
class Disaster:
	type: DisasterType
	position: Tuple[float, float]
	radius: float
	duration: int
	intensity: float
	current_duration: int = 0
	
	def affect_area(self, world: 'World'):
		for organism in world.organisms:
			distance = math.sqrt(
				(organism.position[0] - self.position[0]) ** 2 +
				(organism.position[1] - self.position[1]) ** 2
			)
			if distance <= self.radius:
				damage = self.intensity * (1 - distance / self.radius)
				if self.type == DisasterType.FIRE:
					organism.energy -= damage * 50
				elif self.type == DisasterType.FLOOD:
					if organism.species == Species.PLANT:
						organism.energy -= damage * 30
				elif self.type == DisasterType.DROUGHT:
					if organism.species == Species.PLANT:
						organism.energy -= damage * 20
				elif self.type == DisasterType.DISEASE:
					if not organism.immune_to_disease:
						organism.energy -= damage * 10
						if random.random() < 0.1:
							organism.immune_to_disease = True


@dataclass
class Terrain:
	type: TerrainType
	elevation: float  # 0-1
	temperature_modifier: float
	resource_modifier: float


@dataclass
class Gene:
	name: str
	value: float
	mutation_rate: float
	
	def mutate(self):
		if random.random() < self.mutation_rate:
			self.value += random.uniform(-0.1, 0.1)
			self.value = max(0, min(1, self.value))


@dataclass
class Organism:
	species: Species
	genes: Dict[str, Gene]
	energy: float
	position: Tuple[float, float]
	size: float
	age: int = 0
	social_group: Optional[SocialGroup] = None
	immune_to_disease: bool = False
	migration_target: Optional[Tuple[float, float]] = None
	current_diseases: List[Disease] = None
	
	def __post_init__(self):
		self.current_diseases = []
	
	def update(self, world: 'World') -> List['Organism']:
		self.age += 1
		self.energy -= self.size * 0.5 * (1 + len(self.current_diseases) * 0.2)
		
		# Movement and hunting/foraging
		speed = self.genes['speed'].value
		perception = self.genes['perception'].value
		
		# Find nearby organisms and resources
		nearby_organisms = self._get_nearby_organisms(world)
		nearby_resources = self._get_nearby_resources(world)
		
		offspring = []
		
		# Species-specific behaviors
		if self.species == Species.PLANT:
			self._handle_plant_behavior(world)
		elif self.species == Species.HERBIVORE:
			self._handle_herbivore_behavior(world, nearby_organisms)
		elif self.species == Species.CARNIVORE:
			self._handle_carnivore_behavior(world, nearby_organisms)
		elif self.species == Species.OMNIVORE:
			self._handle_omnivore_behavior(world, nearby_organisms, nearby_resources)
		
		# Handle diseases
		self._update_diseases()
		
		# Handle migration
		if self._should_migrate(world):
			self._handle_migration(world)
		
		# Reproduction
		if (self.energy > 100 * self.size and
				random.random() < self.genes['reproduction_rate'].value):
			offspring.extend(self._reproduce())
		
		return offspring
	
	def _get_nearby_organisms(self, world: 'World') -> List['Organism']:
		perception_range = self.genes['perception'].value * 50
		return [
			org for org in world.organisms
			if org != self and self._distance_to(org.position) < perception_range
		]
	
	def _get_nearby_resources(self, world: 'World') -> List['Resource']:
		perception_range = self.genes['perception'].value * 50
		x, y = self.position
		terrain = world.geography.terrain_map[int(x)][int(y)]
		return [
			resource for resource in world.resources
			if self._distance_to(resource.position) < perception_range
		]


class DisasterType(Enum):
	FIRE = "fire"
	FLOOD = "flood"
	DROUGHT = "drought"
	DISEASE = "disease"


@dataclass
class Disease:
	name: str
	infection_rate: float
	mortality_rate: float
	duration: int
	resistance_gene: str


class SocialGroup:
	def __init__(self, species: 'Species'):
		self.members: Set['Organism'] = set()
		self.species = species
		self.leader: Optional['Organism'] = None
		self.territory_center: Tuple[float, float] = (0, 0)
		self.territory_radius: float = 20.0
	
	def update_territory(self):
		if self.members:
			x_coords = [m.position[0] for m in self.members]
			y_coords = [m.position[1] for m in self.members]
			self.territory_center = (np.mean(x_coords), np.mean(y_coords))
	
	def choose_leader(self):
		if self.members:
			self.leader = max(self.members, key=lambda x: x.genes['leadership'].value)


@dataclass
class Disaster:
	type: DisasterType
	position: Tuple[float, float]
	radius: float
	duration: int
	intensity: float
	current_duration: int = 0
	
	def affect_area(self, world: 'World'):
		for organism in world.organisms:
			distance = math.sqrt(
				(organism.position[0] - self.position[0]) ** 2 +
				(organism.position[1] - self.position[1]) ** 2
			)
			if distance <= self.radius:
				damage = self.intensity * (1 - distance / self.radius)
				if self.type == DisasterType.FIRE:
					organism.energy -= damage * 50
				elif self.type == DisasterType.FLOOD:
					if organism.species == Species.PLANT:
						organism.energy -= damage * 30
				elif self.type == DisasterType.DROUGHT:
					if organism.species == Species.PLANT:
						organism.energy -= damage * 20
				elif self.type == DisasterType.DISEASE:
					if not organism.immune_to_disease:
						organism.energy -= damage * 10
						if random.random() < 0.1:
							organism.immune_to_disease = True


class TerrainType(Enum):
	WATER = "water"
	PLAINS = "plains"
	FOREST = "forest"
	MOUNTAIN = "mountain"
	DESERT = "desert"
	SWAMP = "swamp"
	TUNDRA = "tundra"


@dataclass
class Organism:
	species: Species
	genes: Dict[str, Gene]
	energy: float
	position: Tuple[float, float]
	size: float
	age: int = 0
	social_group: Optional[SocialGroup] = None
	immune_to_disease: bool = False
	migration_target: Optional[Tuple[float, float]] = None
	current_diseases: List[Disease] = None
	
	def __post_init__(self):
		self.current_diseases = []
	
	def update(self, world: 'World') -> List['Organism']:
		self.age += 1
		self.energy -= self.size * 0.5 * (1 + len(self.current_diseases) * 0.2)
		
		# Handle diseases
		self._update_diseases()
		
		# Handle migration
		if self._should_migrate(world):
			self._handle_migration(world)
		
		# Handle social behavior
		if self.social_group:
			self._handle_social_behavior()
		
		# Regular behavior
		offspring = super().update(world)
		
		# Check for disasters
		self._handle_disasters(world)
		
		return offspring
	
	def _update_diseases(self):
		for disease in self.current_diseases[:]:
			if random.random() < disease.mortality_rate:
				self.energy -= 20
			if random.random() < self.genes.get(disease.resistance_gene, Gene('resistance', 0.1, 0.1)).value:
				self.current_diseases.remove(disease)
				self.immune_to_disease = True
	
	def _should_migrate(self, world: 'World') -> bool:
		# Check season and temperature conditions
		if world.season in [1, 3]:  # Summer or Winter
			temp = world.weather.temperature
			if (self.species != Species.PLANT and
					((temp > 30 and world.season == 1) or
					 (temp < 5 and world.season == 3))):
				return True
		return False
	
	def _handle_migration(self, world: 'World'):
		if not self.migration_target:
			# Find suitable new location based on temperature
			new_x = random.uniform(0, world.size[0])
			new_y = random.uniform(0, world.size[1])
			self.migration_target = (new_x, new_y)
		
		# Move towards target
		current_x, current_y = self.position
		target_x, target_y = self.migration_target
		
		speed = self.genes['speed'].value * 2
		dx = np.clip(target_x - current_x, -speed, speed)
		dy = np.clip(target_y - current_y, -speed, speed)
		
		self.position = (current_x + dx, current_y + dy)
	
	def _handle_social_behavior(self):
		if self == self.social_group.leader:
			# Leader behavior
			self.energy += 5  # Leaders get extra energy from group success
		else:
			# Follower behavior
			distance_to_center = math.sqrt(
				(self.position[0] - self.social_group.territory_center[0]) ** 2 +
				(self.position[1] - self.social_group.territory_center[1]) ** 2
			)
			if distance_to_center > self.social_group.territory_radius:
				# Move back towards territory
				self.position = (
					self.position[0] + (self.social_group.territory_center[0] - self.position[0]) * 0.1,
					self.position[1] + (self.social_group.territory_center[1] - self.position[1]) * 0.1
				)


class World:
	def __init__(self, size: Tuple[int, int]):
		# Previous initialization code remains...
		self.disasters: List[Disaster] = []
		self.social_groups: Dict[Species, List[SocialGroup]] = defaultdict(list)
		self.diseases: List[Disease] = self._initialize_diseases()
	
	def _initialize_diseases(self) -> List[Disease]:
		return [
			Disease("flu", 0.3, 0.1, 10, "immune_system"),
			Disease("plague", 0.5, 0.3, 20, "plague_resistance"),
			Disease("virus", 0.4, 0.2, 15, "viral_resistance")
		]
	
	def update(self):
		# Previous update code remains...
		
		# Update disasters
		self._update_disasters()
		
		# Update social groups
		self._update_social_groups()
		
		# Spread diseases
		self._spread_diseases()
		
		# Generate random disasters
		self._generate_disasters()
	
	def _update_disasters(self):
		for disaster in self.disasters[:]:
			disaster.affect_area(self)
			disaster.current_duration += 1
			if disaster.current_duration >= disaster.duration:
				self.disasters.remove(disaster)
	
	def _update_social_groups(self):
		for groups in self.social_groups.values():
			for group in groups:
				group.update_territory()
				group.choose_leader()
	
	def _spread_diseases(self):
		for organism in self.organisms:
			if organism.current_diseases:
				nearby = organism._get_nearby_organisms(self)
				for disease in organism.current_diseases:
					for target in nearby:
						if (random.random() < disease.infection_rate and
								disease not in target.current_diseases and
								not target.immune_to_disease):
							target.current_diseases.append(disease)
	
	def _generate_disasters(self):
		if random.random() < 0.01:  # 1% chance each day
			disaster_type = random.choice(list(DisasterType))
			self.disasters.append(Disaster(
				type=disaster_type,
				position=(random.uniform(0, self.size[0]),
				          random.uniform(0, self.size[1])),
				radius=random.uniform(10, 30),
				duration=random.randint(5, 20),
				intensity=random.uniform(0.3, 1.0)
			))


# Example usage:
world = World((100, 100))
for _ in range(365):
	world.update()
	if _ % 10 == 0:
		stats = world.get_stats()
		print(f"\nDay {stats['day']}:")
		print(f"Population: {stats['population']}")
		print(f"Weather: {stats['weather']}")
		print(f"Active Disasters: {len(world.disasters)}")
		print(f"Disease Infections: {sum(len(org.current_diseases) for org in world.organisms)}")