# Git Hygiene for *Moral Despair*

## TL;DR (the 60‑second version)

- **Never push to `main`.** One maintainer merges `dev → main`.
- **Everyone works in `dev`**, either directly or via short‑lived feature branches.
- **Create feature branches from `dev`, not `main`.**
- **You may merge your own feature branch back into `dev`** when it’s ready.
- **No force‑pushes to shared branches. Ever.**
- **If your merge breaks `dev`, you help fix it.** No blame.
- When unsure, **open a PR or ask** — that’s collaboration, not friction.

If you remember nothing else: *`main` is sacred, `dev` is shared, feature branches are sandboxes.*

---

## The Big Picture (read this first)

- **`main` is sacred** — stable, playable, trustworthy
- **`dev` is collaborative** — active work lives here
- **Feature / personal branches are sandboxes** — experiment freely, then merge back

No one is expected to be perfect. Rollbacks are normal. Questions are welcome.

---

## Branches and What They’re For

### `main`
**What it represents**
- The canonical state of the world
- Should always compile / boot / load cleanly

**Rules**
- 🚫 No direct pushes
- ✅ Only the designated maintainer merges into `main`
- ✅ All changes flow from `dev → main`

Think of `main` as: *“This is what we’d let players log into.”*

---

### `dev`
**What it represents**
- The shared workshop
- Where active development happens

**Rules**
- ✅ Everyone may push to `dev`
- ❌ No force‑pushes
- ❌ No rebasing shared history

`dev` can be a little messy — that’s okay. It should still mostly work.

---

### Feature / Personal Branches (optional but encouraged)

These are **short‑lived branches** for focused work.

**Create them from `dev`:**
```bash
git checkout dev
git pull origin dev
git checkout -b feature/your-thing
```

**Naming examples**
- `feature/map-vesla-outer`
- `npc/candera-merchant`
- `fix/incorrect-exit`

**Rules**
- ✅ Branch from `dev`
- ✅ Commit freely
- ✅ Merge back into `dev` when ready
- ❌ Never merge directly into `main`
- ❌ Delete the branch after merging (this is healthy!)

Feature branches are **sandboxes**, not long‑term homes.

---

## Who Can Merge What?

- **Feature branch → `dev`**
  - The branch author may merge their own work
  - Others may merge it with discussion/consent

- **`dev` → `main`**
  - Only the designated maintainer

If you’re unsure whether something is safe to merge into `dev`, open a PR instead. That’s a *pause*, not a punishment.

---

## Commits: Small, Honest, Human

Good commit messages help everyone — including you in six months.

**Good examples**
- `Add outer wall rooms to Vesla`
- `Fix incorrect south exit in globe room_12_25`
- `Initial aging pass for Candera market`

**Please avoid**
- `stuff`
- `wip`
- `oops`

Rule of thumb:
> One logical change per commit, explained like you’re writing a note to a friend.

---

## Merging Back Into `dev`

Before you merge:
- Does it compile / load?
- Does it avoid unrelated changes?
- Does the commit history tell a clear story?

Then:
```bash
git checkout dev
git pull origin dev
git merge feature/your-thing
git push origin dev
```

Afterwards:
- Delete the feature branch
- Take a breath — you’re done

---

## Social Contracts (Important)

Some parts of the project benefit from extra care:

- **Lore & prose files** → discuss big rewrites first
- **Core systems** → announce intent before refactors
- **Generated content** → don’t hand‑edit unless agreed

This isn’t about permission — it’s about respect and avoiding surprises.

---

## If Something Goes Wrong

It will. That’s normal.

- Rollbacks are allowed
- Fixes are collaborative
- No one gets blamed for honest mistakes

The only real rule is:
> If your merge breaks `dev`, you help fix it.

That’s it.

---

## Final Thought

This repository should feel **safe to work in**.

If you ever feel unsure, blocked, or confused:
- Ask
- Open a PR
- Or just say “hey, I’m not sure about this”

We’re building something together. Let’s make it sustainable.

