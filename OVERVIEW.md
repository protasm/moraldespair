# Moral Despair — Project Overview

## High-Level Description

**Moral Despair** is a custom LPMud mudlib designed to run on the **LDMud** driver. It is deployed on an AWS EC2 instance and publicly accessible at:

```
mud.moraldecay.net 3003
```

The project represents a *reboot* or *successor* to the early‑1990s LPMud **Moral Decay**. While it shares the same world and geography, Moral Despair is **not** intended to recreate the original game mechanically, narratively, or system‑by‑system. Instead, it is a clean restart with modern design goals, implemented incrementally through clearly defined development phases.

This repository contains **only the mudlib** (game logic, world definitions, commands, systems, etc.), not the LDMud driver itself.

---

## Relationship to Moral Decay (Legacy MUD)

- Moral Despair is set in **the same fictional world** as Moral Decay
- The timeline is advanced **approximately 200 years**
- The geography, city layouts, and major regions may resemble the original world
- No original quests, NPCs, items, mechanics, or balance assumptions are being preserved

Think of Moral Despair as a *world reboot*, not a remake.

The design intent is to leverage **player nostalgia and spatial memory** ("I know this place…") while allowing the game itself to grow into something new, coherent, and deliberately paced.

---

## Core Design Philosophy

1. **Start Empty, Then Build**
   - Systems should be introduced gradually
   - Nothing exists unless explicitly designed and implemented

2. **Phased Development**
   - The game evolves over time through defined phases
   - Each phase unlocks new mechanics, entities, and complexity

3. **World First, Systems Second**
   - Geography and navigation come before NPCs, items, or combat
   - Early gameplay focuses on exploration and presence

4. **Maintainability and Clarity**
   - Code should be explicit, readable, and conservative
   - Avoid clever abstractions unless clearly justified

This repo is intentionally structured to support **iterative expansion** rather than a monolithic finished design.

---

## Phase 1: The Abandoned World

**Phase 1 represents the starting state of the game.**

### Narrative State

- The world has been **entirely abandoned for centuries**
- Cities are ruins; roads are broken; landmarks are weathered
- No living creatures remain **except vegetation**
- There are no NPCs, monsters, merchants, or quest givers

The world is silent. Whatever conflicts once existed are long over.

### Gameplay Constraints

During Phase 1:

- **Rooms and exits exist**
- **No items** exist
- **No NPCs or mobs** exist
- **No combat** exists
- Players have **very limited abilities**

Players may:
- Connect to the game
- Move through the world
- Observe descriptions
- Gradually learn the geography

Phase 1 is intentionally sparse and atmospheric.

---

## Player Experience Goals (Phase 1)

- Evoke a sense of **loneliness and aftermath**
- Encourage slow exploration rather than optimization
- Allow returning players to recognize familiar places in ruin
- Establish emotional weight before introducing mechanics

This phase is meant to feel *haunting*, not incomplete.

---

## Technical Notes for Codex / Contributors

When working on this repository:

- Assume **Phase 1 constraints apply unless explicitly stated otherwise**
- Do not introduce NPCs, items, combat systems, or economies prematurely
- Prefer simple, explicit LPC patterns over abstraction
- Treat world files (rooms, areas) as first‑class content

Future phases will deliberately relax these constraints.

---

## Future Direction (High-Level)

Later phases (not implemented yet) may include:

- Return of NPC populations
- Emergent factions and threats
- Gradual restoration or transformation of regions
- Player influence on world state

None of these systems should be assumed to exist yet.

---

## Summary

Moral Despair is a deliberately slow‑built LPMud set in a familiar but abandoned world. The current goal is not feature completeness, but **foundation, atmosphere, and correctness**.

All development decisions should preserve that intent.

