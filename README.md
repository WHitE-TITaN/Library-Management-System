# 📚 Library Management System

A user-friendly desktop-based Library Management System built using **C++ and Qt 6**. This application helps manage books, members, and book issuing/returning efficiently with a clean GUI.

## ✨ Features

- ➕ Add new books with stock count
- 👤 Register and manage library members
- 📖 Issue books to members (for 15 days)
- 🔁 Return books and calculate fines for late returns
- 🕵️ View all current issuers of any book
- ❌ Prevent duplicate issuance
- ⚠️ Fine warning for late returns
- 💬 Interactive message boxes for user guidance

## 🧱 Tech Stack

- **C++** (Core logic)
- **Qt 6** (UI and integration)
- **Qt Designer** (For building UI forms)

## 📂 Project Structure

```
Library-Management-System/
├── book.h / book.cpp         # Book-related logic
├── members.h / members.cpp   # Member records & validation
├── informationWareHouse.h/cpp # Central access and bridge logic
├── returnbook.ui/.cpp/.h     # Book return UI and handler
├── allissuers.ui/.cpp/.h     # UI for viewing issuers
├── addbook.ui/.cpp/.h        # UI for adding a new book
├── mainwindow.ui/.cpp/.h     # Home screen
└── main.cpp                  # App entry point
```

## 🛠 How to Build

1. **Install Qt (6.x recommended)**  
   - [Download Qt](https://www.qt.io/download)
   - Ensure you have `Qt Creator` and `MinGW` if using Windows

2. **Clone this repo**

   ```bash
   git clone https://github.com/your-username/Library-Management-System.git
   cd Library-Management-System
   ```

3. **Open in Qt Creator**
   - Open the `.pro` or `.qmake` file
   - Configure and run the project

## 📝 Usage

1. Launch the app
2. Use the menu to:
   - Add books to the catalog
   - Register members
   - Issue or return books
   - View book issuers and due dates

## 🔐 Access Control

- Basic user verification through member IDs
- Duplicate book issues are automatically blocked

## 📅 Fine Calculation

Late return is calculated based on the difference between the system date and the recorded expiry date. A fine is shown if the return is overdue.

---

## 🤝 Contributing

Feel free to fork and suggest improvements! New features like search, member history, or database support are welcome.

## Original LLD
- https://github.com/WHitE-TITaN/Low-Level-design/tree/Master/Library-Book-System