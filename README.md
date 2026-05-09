# Design Patterns - C++
Most Commonly Used Design Patterns and their examples in C++

# Singleton
- Only a single global instance of the class exists
- Used for things like loggers, configuration managers etc
- Example in this repo: Logger

# Observer
- One to Many dependency. State change in the Publisher object is convery automatically to the observer objects
- Observers can attach or detach to publisher objects
- Publishers can notify the Observers about the state change
- Used for things like Weather Station, YouTube, News
- Example in this repo: News Publisher to Subscribers (Observers)

# Factory Method
- It defines an interface to define an object but lets subclasses decide which class to instantiate.
- User for things like UI frameworks/ Game Development
- Example in this repo: Pizza Store and Pizza Type

# Abstract Factory
- Abstract Factory is a creational design pattern that provides an interface to create families of related objects without specifying their concrete classes.
- It is used when you need multiple objects that belong together (a "product family") to ensure consistency.
- Example in this repo: ItalianMealFactory creates a complete matching Italian meal (Margherita Pizza + Cola), while MexicanMealFactory creates a matching Mexican meal (Mexican Pizza + Margarita).

# Strategy
- Strategy pattern allows you to swap different algorithms or behaviors at runtime.
- It helps you write flexible code where behavior can be changed without modifying the main class.
- Example in this repo: A Sorter class can use QuickSort or BubbleSort at runtime by switching strategies.

# Builder
- Builder pattern is used to construct complex objects step by step.
- It solves the problem of having large constructors with many optional parameters.
- Example in this repo: PizzaBuilder builds a pizza by setting size → crust → sauce → toppings step by step.

# Decorator
- Decorator pattern allows you to add new responsibilities to an object dynamically.
- It provides a flexible alternative to subclassing for extending functionality.
- Example in this repo: You can decorate a simple Coffee with Milk and Sugar at runtime to add features.
