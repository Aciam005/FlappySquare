**FlappySquare – Proiect Embedded Game (C++/PlatformIO)**

Dezvoltarea unui joc de tip „arcade” pentru sisteme embedded, implementat în limbajul C++ utilizând framework-ul Arduino și mediul de dezvoltare PlatformIO. Proiectul demonstrează aplicarea principiilor de programare orientată pe obiect (OOP) și gestionarea eficientă a resurselor hardware într-un mediu cu constrângeri tehnice.

**Elemente tehnice cheie:**

* **Arhitectură Modulară:** Implementarea unei structuri decuplate prin sisteme dedicate pentru gestionarea scenelor (SceneManager), a resurselor grafice (SpriteManager) și a logicii de joc.
* **Interfațare Hardware:** Integrarea unui display TFT (driver ILI9341) prin protocolul de comunicare SPI, utilizând bibliotecile Adafruit GFX și BusIO pentru randare grafică optimizată.
* **Sistem de Randare:** Dezvoltarea unui motor de randare custom care gestionează coordonatele vectoriale (Vector2) și obiectele grafice pentru o experiență de utilizare fluidă.
* **Programare Low-level:** Configurarea pinilor GPIO și gestionarea interrupțiilor sau a input-ului pentru controlul personajului în timp real.
* **Clean Code:** Organizarea riguroasă a codului sursă în componente reutilizabile și headere dedicate (Constants, PinDefinitions, Colors), facilitând scalabilitatea și mentenanța proiectului.
