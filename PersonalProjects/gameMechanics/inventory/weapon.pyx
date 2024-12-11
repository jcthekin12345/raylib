from libc.stdlib cimport rand, RAND_MAX

# Define C-level types for performance
cdef class Weapon:
	cdef public str name
	cdef public double damage
	cdef double critical_chance
	cdef double critical_multiplier
	cdef int level
	cdef bint is_broken
	
	def __init__(self, str name, double damage, double critical_chance=0.1, double critical_multiplier=0.5, int level):
		self.max_durability = None
		self.name = name
		self.critical_chance = critical_chance
		self.critical_multiplier = critical_multiplier
		self.damage = damage
		self.level = 1
		self.is_broken = False
	
	# Fast C-level method for damage calculation
	cdef double calculate_damage(self) nogil:
		cdef double base_damage = self.damage * (self.durability / self.max_durability)
		cdef double random_value = rand() / float(RAND_MAX)
		
		if random_value < self.critical_chance:
			return base_damage * 2.0
		return base_damage
	
	# Public method that uses the fast C calculation
	cpdef attack(self):
		if self.is_broken:
			return 0.0
		
		self.durability -= 1
		if self.durability <= 0:
			self.is_broken = True
			return 0.0
		
		return self.calculate_damage()
	
	# C-optimized level scaling
	cpdef level_up(self):
		self.level += 1
		self.damage *= 1.2
		self.max_durability = int(self.max_durability * 1.1)
		self.durability = self.max_durability

# Specialized ranged weapon with C-level optimizations
cdef class RangedWeapon(Weapon):
	cdef public double range
	cdef public int ammo
	cdef public int max_ammo
	
	def __init__(self, str name, double damage, double range, int max_ammo, **kwargs):
		super().__init__(name, damage, **kwargs)
		self.range = range
		self.max_ammo = max_ammo
		self.ammo = max_ammo
