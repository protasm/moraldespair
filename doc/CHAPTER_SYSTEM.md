# Chapter System Overview

This document captures the chapter tracking primitives used by avatar saves
and the chapter daemon.

## Avatar Save Excerpts

Avatar save data stores only stable chapter IDs, never filesystem paths:

```
([
  "display_name" : "Bluto",
  "brief" : 0,
  "last_played" : 1720000000,
  "current_chapter" : "prologue",
  "unlocked_chapters" : ({ "prologue" })
])
```

## Example Usage

### Setting an Avatar's Current Chapter

```
string desired;
int updated;

desired = "prologue";
updated = avatar->set_current_chapter(desired);

if (!updated)
  write("That chapter is unknown.\n");
```

### Spawning into the Correct Chapter Start Room

```
string start_room;

start_room = CHAPTER_D->resolve_avatar_start_room(avatar);
avatar->move(start_room);
avatar->show_location();
```

### Rejecting Invalid or Locked Chapters

```
string requested;

requested = "chapter_2";

if (!CHAPTER_D->chapter_exists(requested)) {
  write("That chapter does not exist.\n");
} else if (!CHAPTER_D->can_avatar_access(avatar, requested)) {
  write("You have not unlocked that chapter.\n");
} else {
  avatar->set_current_chapter(requested);
}
```
