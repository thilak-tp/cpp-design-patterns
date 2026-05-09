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
- User for things like Weather Station, YouTube, News
- Example in this repo: News Publisher to Subscribers (Observers)
