# Ekosystem
### Introduction
Ekosystem is an application created for educational purposes.

It features the usage of:
- Object-oriented C++
- Layered architecture
- MVP architectural pattern
- Design patterns
  - Adapter
  - Singleton
- QtQuick

### Details

The source code consists of 3 layers:
- `Domain`
- `Presentation` (depends on `Domain`)
- `Application` (depends on `Presentation`)

#### Domain layer

Allows for **simulating** step-by-step interactions of simple organism models (defined as `Organism` derivatives) on a **Cartesian plane**.
Currently, there are only two organisms implemented:
- `Virus`
  - creates another `Virus` if there is a `Human` in the same tile
- `Human`
  - coughs every 5 ticks, spreading very small organisms in the vicinity

Warning: Any observations made with the help of this simulation, should be subject to a critical analysis :)

#### Presentation layer

Implemented with MVP architectural pattern, provides a well defined interface for domain use cases.
Aside from that, it features a centralised state management system based on **event bus** and **single source of truth**.

#### Application layer

Implemented with **QtQuick**, provides a **GUI** for presentation layer. Any lists are populated by their respective `Model`s.
Any Actions are dispatched by calling `Presenter`s methods directly from `onClick` handlers of **QML** objects.
`Presenter`s are exposed to **QML** via `Adapter`s to avoid contaminating presentation layer with **Qt** dependencies.
