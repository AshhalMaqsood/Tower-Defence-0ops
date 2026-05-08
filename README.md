# Tower Defense Game — OOP Project

A fully functional Tower Defense game built in C++ using SFML 3.0,
developed as part of an Object-Oriented Programming course project.

## Gameplay
- Defend your base by placing towers along the enemy path
- Survive 10 progressive waves of enemies
- Earn gold by killing enemies and spend it to place towers
- Lose a life each time an enemy reaches the exit
- Survive all waves to win!

## Features
- 5 Enemy Types: Basic, Fast, Tank, Flying, Shield
- 5 Tower Types: Cannon, Sniper, Machine Gun, Slow, Explosive
- Animated bullet visuals for each tower
- HP bars on all enemies
- Economy system with gold and tower costs
- Progressive wave difficulty
- Pause menu, Game Over screen, Win screen, Guide screen
- Background music and sound effects

## How to Compile and Run
1. Install SFML 3.0 from https://www.sfml-dev.org/
2. Open the .sln file in Visual Studio
3. Make sure SFML is linked correctly in project properties
4. Build and Run (Debug x64)

## GUI Library
- SFML 3.0 (Simple and Fast Multimedia Library)

## OOP Concepts Used
- Inheritance and Polymorphism
- Abstract base classes (Entity, Enemy, Tower)
- Runtime polymorphism via base class pointers
- Encapsulation with getters and setters
- Operator overloading

## Known Issues / Limitations
- Single map only
- No tower upgrade system
