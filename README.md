# 🕒 Gantt Chart Simulator (C)

A group of two college project.

A command-line program that allows users to **create, view, and manage Gantt charts** for project scheduling.  
Built entirely in C to practice **structs, file I/O, and dependency management**.

---

## 🚀 Features
- Create a new Gantt chart or load a predefined one.
- Add, edit, or delete tasks interactively.
- Detect **circular dependencies** between tasks.
- Compute the **critical path** to identify bottlenecks.
- Save and reload project data using text files.

---

## 🧩 Example Use
```bash
$ ./gantt_chart
Would you like to use the test example or create your own Gantt from scratch? (test or create)
$ test
[displays preloaded chart]
If you wish to edit the Gantt please type "edit" / If you wish to run a test, type "test" or to exit, type "quit" and then press enter to execute your option.
$ test
Enter the name of the task you would like to test: (Type "ALL" to test all tasks.)
$ Build_Foundation
Dependency Chain for Build_Foundation:
-> 4 -> 3 -> 1 
     -> 3 -> 2 -> 1 
```
---

## 🧠 Core Concepts
Graph traversal (DFS) for circular dependency detection.
Topological sorting for task ordering.
Critical Path Method (CPM) for computing project duration.
File I/O to save/load project state.

---

## ⚙️ Tech Stack
Language: C
Tools: gcc, make, stdio.h, stdlib.h, string.h

---

## 👨‍💻 Author
David Neskrabal
Undergraduate Computer Science Student @ University College Dublin
