# Queue Data Structures & Round Robin Scheduling in C

This repository contains C implementations of standard Queue data structures and their application in CPU scheduling.

## 📂 Contents

1.  **Linear Queue**: A standard First-In-First-Out (FIFO) data structure using an array.
2.  **Circular Queue**: An optimized version of the queue that reuse vacated space by wrapping around the array indices.
3.  **Round Robin Scheduling**: A practical application of the Circular Queue used in Operating Systems to manage process execution using a Time Quantum.

---

## 1. Linear Queue
The Linear Queue follows the strict FIFO principle. However, it suffers from "memory wastage" because once the `rear` reaches the maximum size, no more elements can be added even if the `front` has moved forward (leaving empty spaces at the beginning).

**Features:**
*   `enqueue()`: Add elements to the back.
*   `dequeue()`: Remove elements from the front.
*   `peek()`: View the front-most element.
*   `display()`: Print the current state of the queue.

---

## 2. Circular Queue
The Circular Queue solves the limitation of the Linear Queue. By using the modulo operator (`%`), the `rear` and `front` pointers wrap around to the beginning of the array when they reach the end, ensuring maximum memory utilization.

**Key Logic:**
*   **Full Condition:** `(rear + 1) % MAX == front`
*   **Next Position:** `i = (i + 1) % MAX`

---

## 3. Round Robin Scheduling (using Queue)
This program simulates how an Operating System schedules processes. It uses a **Circular Queue** to manage a list of processes waiting for CPU time.

**How it works:**
1.  Every process is assigned a **Time Quantum**.
2.  The process at the front of the queue is executed for the duration of the Time Quantum.
3.  If the process finishes within the quantum, it is removed.
4.  If the process still has remaining burst time, it is sent to the back of the queue to wait for its next turn.
5.  The program calculates **Turnaround Time (TAT)** and **Waiting Time (WT)** for each process.

---

## 🚀 How to Run

### Prerequisites
You need a C compiler (GCC, Clang, or MSVC).

### Compilation
Compile any of the files using GCC:
```bash
# To run Linear Queue
gcc linear_queue.c -o linear

# To run Circular Queue
gcc circular_queue.c -o circular

# To run Round Robin
gcc round_robin.c -o rr
```

### Execution
Run the compiled executable:
```bash
./linear
# OR
./circular
# OR
./rr
```

---

## 📊 Comparison Summary

| Feature | Linear Queue | Circular Queue |
| :--- | :--- | :--- |
| **Memory Usage** | Inefficient (Static limits) | Efficient (Reuses empty slots) |
| **Logic** | `rear++` | `(rear + 1) % MAX` |
| **Overflow** | When `rear == MAX - 1` | When `(rear + 1) % MAX == front` |
| **Best For** | Simple buffering | Resource scheduling (OS), IO Buffers |
