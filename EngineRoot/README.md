Great choice! A **2D top‑down shooter** is perfect for testing your game engine while keeping the scope manageable.  
Here’s a **1‑page Game Design Document (GDD)** followed by a **Feature Roadmap** tailored specifically for building AND testing your engine’s systems.

No searches needed here — this is purely design content.

***

# 🎮 \*\*1‑Page Game Design Document (GDD)

Project Title: “ARC‑RUNNER” (placeholder)\*\*

## **High Concept**

A fast‑paced 2D top‑down shooter where the player fights through procedurally arranged rooms filled with enemies. The focus is on tight controls, satisfying weapons, and quick, readable combat. Inspired by **Enter the Gungeon**, **Nuclear Throne**, and classic twin‑stick arcade shooters.

***

## **Core Gameplay**

*   Player moves in 360 degrees.
*   Player aims independently with mouse or right stick.
*   Shoot enemies, dodge attacks, collect temporary powerups.
*   Rooms are small combat arenas; clearing enemies opens exits.
*   Every run is short, skill‑based, and replayable.

***

## **Player Abilities**

*   **Move** (WASD or left stick)
*   **Aim** (mouse or right stick)
*   **Shoot** (left mouse / right trigger)
*   **Dash** (i‑frames, cooldown)
*   **Interact** (doors, pickups)

***

## **Weapons & Items**

*   Basic pistol (infinite ammo)
*   Shotgun (spread, slow reload)
*   Auto‑rifle (fast fire rate)
*   Powerups:
    *   Damage boost (temporary)
    *   Movement speed boost
    *   “Bullet Time” charge

***

## **Enemies**

Each enemy tests a different part of your engine:

*   **Grunt**: walks toward player, melee hit
*   **Shooter**: fires slow bullets
*   **Dasher**: charges at player
*   **Turret**: stationary, rotates to shoot

***

## **Rooms / Levels**

*   Simple grid‑based rooms (8×6 tiles).
*   Random room layout from prefab room files.
*   Rooms include:
    *   Enemies
    *   Obstacles
    *   Cover objects
    *   Hazards (spikes, barrels)

***

## **Art Style**

*   Simple pixel‑art placeholder sprites
*   Low‑detail, high‑readability silhouettes
*   Bright bullets & impacts

***

## **Audio Style**

*   Synth‑wave inspired tracks
*   Punchy weapon SFX
*   Enemy growls and beeps
*   Dash “whoosh” sound

***

## **Win / Lose Conditions**

*   **Lose**: Player hp reaches 0.
*   **Win**: Complete all rooms in the run (e.g. 10 rooms).

***

## **Target Platforms**

*   Desktop (Windows, macOS, Linux)
*   Gamepad & mouse/keyboard support

***

# 🚀 **Feature Roadmap (Engine‑Aligned)**

Organized so each feature actively validates your engine systems as you develop them.

***

# **PHASE 1 — Foundations (Engine Systems Bootstrapping)**

### 🎯 Goal: Minimum playable scene

**Engine features exercised:**

*   Core loop
*   Input system
*   Sprite rendering
*   Scene graph
*   ECS basics

**Game features to implement:**

1.  Player entity
2.  Move player with WASD
3.  Aim with mouse
4.  Render simple player sprite
5.  Camera that follows player
6.  One empty room (testing scene)

***

# **PHASE 2 — Combat Core (Gameplay Systems)**

### 🎯 Goal: Gunplay test scenario

**Engine features tested:**

*   ECS systems
*   Collision detection
*   Resource loading
*   Audio playback
*   Entity spawning/despawning

**Game features to implement:**

1.  Shooting system
2.  Bullet entity & lifetime system
3.  Basic enemy entity
4.  Enemy AI (seek player)
5.  Enemy hitboxes & HP
6.  Bullet–enemy collision
7.  Enemy death animation / sound
8.  Player damage + knockback

***

# **PHASE 3 — Rooms & Level Flow**

### 🎯 Goal: Moving room‑to‑room

**Engine features tested:**

*   Scene serialization
*   Prefabs
*   Resource caching
*   Input rebinding (optional)

**Game features:**

1.  Room data files (JSON / YAML)
2.  Load room layouts at runtime
3.  Door triggers
4.  Auto‑spawn enemies per room
5.  Room‑clear detection
6.  Transition to next room
7.  Basic UI (hp bar)

***

# **PHASE 4 — Weapons & Items Expansion**

### 🎯 Goal: Fun gameplay loop

**Engine features tested:**

*   Component data‑driven design
*   Script system (if implemented)
*   Asset hot‑reload
*   Audio mixing

**Game features:**

1.  Alternate weapons (shotgun, auto rifle)
2.  Weapon pickup & switching
3.  Powerups (speed, damage)
4.  Shooting SFX per weapon
5.  Muzzle flash particles

***

# **PHASE 5 — Polishing Tools & Debugging**

### 🎯 Goal: Smooth developer experience

**Engine features tested:**

*   Debug overlay
*   Entity inspector
*   Gizmos
*   Profiling
*   Hot reload

**Game tools/features:**

1.  Show FPS, draw calls, memory usage
2.  Debug mode to spawn enemies/items
3.  Toggle god mode / noclip
4.  Visualize hitboxes
5.  Pause & step‑through update mode
6.  Room preview tool (simple editor window)

***

# **PHASE 6 — Full Loop + Balance**

### 🎯 Goal: Real “Game” structure

**Engine systems tested:**

*   Audio loops & mixing
*   Save system (optional)
*   UI
*   Scene transitions

**Game features:**

1.  Title → Run Start → Lose Screen → Retry
2.  Simple progression (10 rooms)
3.  Difficulty curve adjustments
4.  Boss room (simple AI)
5.  Soundtrack loop

***

# **PHASE 7 — Optional Stretch Features**

Only if you want to expand.

*   Procedural level generator
*   Elite enemy types
*   Weapon mods
*   Skill tree
*   NPC vendor room
*   Mini‑bosses
*   Special ammo types

***

# 🌟 Want me to produce a pixel‑art prototype style guide?

Or a GitHub‑ready README for your game project?

I can also generate:

*   Player + enemy concept sheets
*   Weapon ideas
*   Room layout sketches
*   Data schema for prefabs / rooms
*   A Trello board version of the roadmap

Just tell me what you’d like next!
