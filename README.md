# Rock, Paper, Scissors — C++ Console Game (`rocke33.cpp`)

![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)
![Course](https://img.shields.io/badge/Course-Programming%20Fundamentals-1F8A55)
![University](https://img.shields.io/badge/FAST%20NUCES-Peshawar-D6112C)

An interactive console-based **Rock, Paper, Scissors** arcade game written in C++ as part of my **Programming Fundamentals (PF)** coursework at **FAST NUCES Peshawar**.

---

## Features
- **Modular Function Architecture**: Clean separation between rule display (`displayrules()`), player/computer move handling (`inputuser()`), and round evaluation (`winner()`).
- **Input Validation**: Handles invalid numeric choices gracefully and re-prompts the player without crashing the session.
- **Session Score Tracking**: Accumulates player wins across as many rounds as the player chooses to play.

---

## How to Compile & Run

```bash
g++ rocke33.cpp -o rps_game
./rps_game
```
