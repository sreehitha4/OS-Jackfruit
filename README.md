# 🐳 OS Jackfruit - Container Runtime

## 👩‍💻 Student Details

* **Name:** KARANAM SREEHITHA
* **SRN:** PES1UG24AM129
* **Course:** Operating Systems 
* **Institution:** Pes University
* **Email:** sreehithakaranam@gmail.com

---
# 🐳 OS Jackfruit - Container Runtime

## 👩‍💻 Student Details

* **Name:** Khushi Patel
* **SRN:** PES1UG24AM134
* **Course:** Operating Systems 
* **Institution:** Pes University
* **Email:** khushihpatel06@gmail.com



---
## 📌 Project Overview

This project implements a **basic container runtime** using C programming and Linux system calls. The goal is to understand how containers work internally without using tools like Docker.

The container runtime provides process isolation using `chroot()` and executes commands inside an isolated filesystem (rootfs).

---

## 🎯 Objectives

* Understand container fundamentals
* Implement process isolation using `chroot()`
* Execute commands inside isolated environments
* Manage containers using custom commands
* Learn Linux system calls like `fork()`, `exec()`, `kill()`

---
## 🚀 Tasks Implemented

### ✅ Task 1: Run Container (Foreground)

* Implemented container execution using `fork()` and `chroot()`
* Runs commands inside isolated root filesystem

---

### ✅ Task 2: Background Container Execution

* Used `fork()` to run containers in background
* Allows multiple containers to run simultaneously

---

### ✅ Task 3: Logging Mechanism

* Redirected container output using `dup2()`
* Logs stored in `logs.txt` inside rootfs

---

### ✅ Task 4: Stop Container

* Implemented container stopping using `kill()` / `pkill`
* Allows termination of running containers

---

### ✅ Task 5: Root Filesystem Isolation

* Used Alpine Linux rootfs
* Verified isolation using `/etc/os-release`

---

### ✅ Task 6: Multiple Container Execution

* Demonstrated running multiple containers simultaneously
* Managed using process IDs (PID)

---
## ⚙️ Commands Used

### 🔹 Compile the Project

```bash
make
```

---

### 🔹 Run Container (Foreground)

```bash
sudo ./engine run c1 ../rootfs-alpha /bin/sh
```

---

### 🔹 Start Container (Background)

```bash
sudo ./engine start c1 ../rootfs-alpha sleep 100
```

---

### 🔹 View Running Processes

```bash
ps aux | grep sleep
```

---

### 🔹 View Logs

```bash
./engine logs
```

OR

```bash
cat ../rootfs-alpha/logs.txt
```

---

### 🔹 Stop Container

```bash
./engine stop c1
```

---
## 📸 Screenshots

### 🔹 Task 1: Run Container

<img width="940" height="587" alt="image" src="https://github.com/user-attachments/assets/f6004bc3-7bac-4e54-809c-39c25a4aabc0" />

<img width="940" height="590" alt="image" src="https://github.com/user-attachments/assets/d4c08495-9287-4f60-b685-90e1427f1c93" />

<img width="940" height="587" alt="image" src="https://github.com/user-attachments/assets/f9410cbf-5b19-4255-85c1-a8ae4adc11fc" />



---

### 🔹 Task 2: Background Container Execution

<img width="940" height="586" alt="image" src="https://github.com/user-attachments/assets/b3381aea-a916-4bec-b0db-924fcf2cbfad" />

<img width="940" height="587" alt="image" src="https://github.com/user-attachments/assets/7792e66a-34ce-49c6-b861-d1a0985c93a2" />


---

### 🔹 Task 3: Logs Output

<img width="940" height="517" alt="image" src="https://github.com/user-attachments/assets/d8f48142-3305-4728-bdf5-5c0ece1b74ef" />

<img width="940" height="592" alt="image" src="https://github.com/user-attachments/assets/55ec2068-55b2-4084-a762-71efcd1e3043" />


---

### 🔹 Task 4: Stop Container

<img width="940" height="547" alt="image" src="https://github.com/user-attachments/assets/de63abb8-56fe-4191-acec-798ae6d0d6da" />

<img width="940" height="592" alt="image" src="https://github.com/user-attachments/assets/decfe332-d0f2-41cb-8b13-1b4ea0dab34e" />


---

### 🔹 Task 5: Root Filesystem (Alpine Linux)

<img width="940" height="589" alt="image" src="https://github.com/user-attachments/assets/ec2a7551-6a61-4bb3-a509-32232e4595dd" />


---

### 🔹 Task 6: Multiple Containers

<img width="940" height="584" alt="image" src="https://github.com/user-attachments/assets/8dfce909-73ef-4c86-a89f-bcd59bb1a079" />


---
## 🧠 Key Concepts Used

* **fork()**
  Creates a new process for container execution

* **chroot()**
  Changes root directory to isolate filesystem

* **exec() / execl() / execlp()**
  Executes commands inside the container

* **dup2()**
  Redirects output to log files

* **kill() / pkill()**
  Terminates running container processes

* **Process Isolation**
  Each container runs independently

* **Root Filesystem (rootfs)**
  Provides separate environment for container

---
## 🎯 Conclusion

This project successfully demonstrates the working of a basic container runtime using low-level Linux system calls. It provides insights into how modern container technologies like Docker operate internally.

Through this implementation, we learned process creation, filesystem isolation, command execution, logging mechanisms, and container lifecycle management.

The project serves as a strong foundation for understanding advanced containerization technologies and system-level programming.

---





