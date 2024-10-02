from abc import ABC, abstractmethod
from random import randint


# Base class for all animals
class Animal(ABC):
    def __init__(self, name, species):
        self.name = name
        self.species = species

    @abstractmethod
    def speak(self):
        pass

    @abstractmethod
    def eat(self):
        pass


# Specific animal types
class Canine(Animal):
    def speak(self):
        return f"{self.name} the {self.species} says: Woof!"

    def eat(self):
        return f"{self.name} the {self.species} is eating dog food."


class Feline(Animal):
    def speak(self):
        return f"{self.name} the {self.species} says: Meow!"

    def eat(self):
        return f"{self.name} the {self.species} is eating cat food."


class Bird(Animal):
    def speak(self):
        return f"{self.name} the {self.species} chirps!"

    def eat(self):
        return f"{self.name} the {self.species} is eating seeds."


# Habitat class to describe the environment
class Habitat:
    def __init__(self, type_of_habitat):
        self.type_of_habitat = type_of_habitat

    def describe(self):
        return f"This animal lives in a {self.type_of_habitat} habitat."


# Environmental Conditions
class Weather:
    def __init__(self, condition):
        self.condition = condition

    def is_good_for_outside(self):
        return self.condition in ["sunny", "cloudy"]


# Mixin classes for behaviors
class FetchMixin:
    def fetch(self):
        return f"{self.name} is fetching a stick!"


class ClimbMixin:
    def climb(self):
        return f"{self.name} is climbing a tree!"


class SwimMixin:
    def swim(self):
        return f"{self.name} is swimming in the water!"


# Event system to manage activities
class EventSystem:
    def __init__(self):
        self.events = []

    def schedule_event(self, event):
        self.events.append(event)

    def trigger_events(self):
        for event in self.events:
            event()


# Interaction Mechanism
class AnimalInteraction:
    def interact(self, other):
        return f"{self.name} interacts with {other.name}."


# Dog class inheriting multiple traits and behaviors
class Dog(Canine, FetchMixin, AnimalInteraction):
    def __init__(self, name, habitat_type):
        super().__init__(name, "Dog")
        self.habitat = Habitat(habitat_type)

    def perform_action(self):
        return self.fetch()


# Cat class inheriting multiple traits and behaviors
class Cat(Feline, ClimbMixin, AnimalInteraction):
    def __init__(self, name, habitat_type):
        super().__init__(name, "Cat")
        self.habitat = Habitat(habitat_type)

    def perform_action(self):
        return self.climb()


# Parrot class inheriting multiple traits and behaviors
class Parrot(Bird, SwimMixin, AnimalInteraction):
    def __init__(self, name, habitat_type):
        super().__init__(name, "Parrot")
        self.habitat = Habitat(habitat_type)

    def perform_action(self):
        return self.swim()


# Example usage
if __name__ == "__main__":
    # Create the event system
    event_system = EventSystem()

    # Create animals
    dog = Dog("Buddy", "backyard")
    cat = Cat("Whiskers", "treehouse")
    parrot = Parrot("Polly", "rainforest")

    # Schedule events for the animals
    event_system.schedule_event(lambda: print(dog.perform_action()))  # Buddy fetches
    event_system.schedule_event(lambda: print(cat.perform_action()))  # Whiskers climbs
    event_system.schedule_event(lambda: print(parrot.perform_action()))  # Polly swims

    # Trigger scheduled events
    print("\nScheduled Animal Actions:")
    event_system.trigger_events()

    # Animal interactions
    print("\nAnimal Interactions:")
    print(dog.interact(cat))
    print(cat.interact(parrot))
    print(parrot.interact(dog))

    # Show habitat descriptions
    print("\nHabitat Descriptions:")
    print(dog.habitat.describe())
    print(cat.habitat.describe())
    print(parrot.habitat.describe())

    # Weather conditions affecting animals
    weather = Weather("sunny")
    if weather.is_good_for_outside():
        print("\nThe weather is good for outside activities.")
    else:
        print("\nThe weather is not suitable for outside activities.")
