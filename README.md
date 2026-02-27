**FlappySquare – Embedded Game Project (C++/PlatformIO)**

Development of an "arcade" style game for embedded systems, implemented in C++ using the Arduino framework and the PlatformIO development environment. The project demonstrates the application of object-oriented programming (OOP) principles and efficient hardware resource management within a technically constrained environment.

**Key Technical Elements:**

* **Modular Architecture:** Implementation of a decoupled structure through dedicated systems for scene management (SceneManager), graphical resources (SpriteManager), and game logic.
* **Hardware Interfacing:** Integration of a TFT display (ILI9341 driver) via SPI communication protocol, utilizing Adafruit GFX and BusIO libraries for optimized graphical rendering.
* **Rendering System:** Development of a custom rendering engine that manages vector coordinates (Vector2) and graphical objects for a smooth user experience.
* **Low-level Programming:** GPIO pin configuration and management of interrupts or input for real-time character control.
* **Clean Code:** Rigorous organization of source code into reusable components and dedicated headers (Constants, PinDefinitions, Colors), facilitating project scalability and maintenance.
