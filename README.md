# Contact Management System

## Overview

This Contact Management System is a simple C++ application that allows users to manage their contacts. Users can add, display, search, edit, and delete contacts, as well as load and save contacts from/to a file.

## Features

- **Add Contact**: Add a new contact with name, phone number, and email.
- **Display Contacts**: Display all the contacts stored.
- **Search Contact**: Search for a contact by name.
- **Edit Contact**: Edit the phone number and/or email of an existing contact.
- **Delete Contact**: Delete a contact by name.
- **Load Contacts**: Load contacts from a file.
- **Save Contacts**: Save contacts to a file.

## File Operations

- Contacts are saved to and loaded from a file named `contacts.txt`.
- Each contact is serialized into a single line in the file using a comma-separated format.

## Structure

### Contact Struct

- **Fields**:
  - `std::string name`
  - `std::string phoneNumber`
  - `std::string email`
- **Functions**:
  - `std::string serialize() const`: Converts the contact to a comma-separated string.
  - `static Contact deserialize(const std::string& data)`: Creates a `Contact` object from a comma-separated string.

### Functions

- **`void addContact(std::vector<Contact>& contacts)`**: Prompts the user to input a new contact and adds it to the list.
- **`void displayContacts(const std::vector<Contact>& contacts)`**: Displays all contacts in the list.
- **`void searchContact(const std::vector<Contact>& contacts, const std::string& name)`**: Searches for a contact by name and displays it if found.
- **`int findContactIndex(const std::vector<Contact>& contacts, const std::string& name)`**: Finds the index of a contact by name.
- **`void editContact(std::vector<Contact>& contacts)`**: Prompts the user to edit an existing contact's phone number and/or email.
- **`void deleteContact(std::vector<Contact>& contacts)`**: Prompts the user to delete a contact by name.
- **`void loadContacts(std::vector<Contact>& contacts, const std::string& filename)`**: Loads contacts from a file.
- **`void saveContacts(const std::vector<Contact>& contacts, const std::string& filename)`**: Saves contacts to a file.

## Usage

1. **Compile the Code**:
   Use a C++ compiler to compile the code. For example, using `g++`:
   ```sh
   g++ -o contact_manager contact_manager.cpp

2. **Run the Program**
   Execute the compiled program:
   ```sh
   ./contacts

## Notes
1. Ensure that `contacts.txt` is in the same directory as the executable to load and save contacts properly.
2. Input validation is minimal; it assumes correct input format and does not handle exceptions beyond basic error messages.
