# 🎲 Ludo Dice Roll Action (C Language)

## 📘 Project Overview
The *Ludo Dice Roll Action* project is a simple C program that simulates the dice-rolling mechanism used in the classic board game Ludo. The main objective of this program is to generate a random number between 1 and 6 — representing the faces of a dice — each time the player rolls it.

This project demonstrates the use of:
- Random number generation in C (rand() and srand())
- Control statements
- Basic input/output handling
- Time functions for randomness

---

## ⚙ Features
- Simulates a real dice roll from *1 to 6*
- Allows multiple rolls within a single run
- Uses system time to ensure random results each time
- Clean and easy-to-understand code structure

---

## 🧠 Concepts Used
- stdlib.h → for rand() and srand()
- time.h → to seed the random number generator
- stdio.h → for input/output operations

---

## 💻 How to Run
1. Open the source file ludo_dice_roll.c in any C compiler (like Code::Blocks, Dev-C++, or VS Code).
2. Compile the code:
   ```bash
   gcc ludo_dice_roll.c -o ludo_dice_roll
OUTPUT-

🎲  Ludo - Dice Roll Action (Single Player) 🎲
-------------------------------------------------
Rules:
1) Need a 6 to move out of HOME.
2) Rolling a 6 gives an extra turn.
3) Must land exactly on 57 to win.
-------------------------------------------------

Press R to roll the dice or Q to quit: R

You rolled: 4
❌ You need a 6 to enter the board. Stay at HOME.

Analyzing next step...

Current position: HOME
Press R to roll the dice or Q to quit: Q

You chose to quit. Goodbye!

Thank you for playing Ludo - Dice Roll Action!
