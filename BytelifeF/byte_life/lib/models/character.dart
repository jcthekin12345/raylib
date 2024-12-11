class Character {
  String name;
  int age;
  int happiness;
  Map<String, int> stats = {'intelligence': 50, 'health': 100, 'money': 1000};

  // Constructors in Dart can be fancy!
  Character(this.name, this.age) : happiness = 100;

  // Named constructor - create a random character
  Character.random()
      : age = 0,
        happiness = 100 {
    List<String> possibleNames = ['Alex', 'Sam', 'Jordan', 'Taylor'];
    name = possibleNames[DateTime.now().microsecond % possibleNames.length];
  }

  bool tryActivity(String activity) {
    switch (activity) {
      case 'study':
        stats['intelligence'] = (stats['intelligence']! + 5).clamp(0, 100);
        happiness -= 5;
        return true;
      case 'exercise':
        stats['health'] = (stats['health']! + 10).clamp(0, 100);
        happiness += 5;
        return true;
      default:
        return false;
    }
  }
}
