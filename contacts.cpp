#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Structure to represent a contact
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;

    // Function to serialize a contact into a string
    std::string serialize() const {
        return name + "," + phoneNumber + "," + email;
    }

    // Function to deserialize a contact from a string
    static Contact deserialize(const std::string& data) {
        Contact contact;
        size_t pos1 = data.find(',');
        size_t pos2 = data.find(',', pos1 + 1);
        contact.name = data.substr(0, pos1);
        contact.phoneNumber = data.substr(pos1 + 1, pos2 - pos1 - 1);
        contact.email = data.substr(pos2 + 1);
        return contact;
    }
};

// Function to add a contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::getline(std::cin, newContact.name);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newContact.phoneNumber);
    std::cout << "Enter email: ";
    std::getline(std::cin, newContact.email);
    contacts.push_back(newContact);
}

// Function to display all contacts
void displayContacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    std::cout << "Contacts List:" << std::endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << "Contact " << (i + 1) << ":" << std::endl;
        std::cout << "Name: " << contacts[i].name << std::endl;
        std::cout << "Phone Number: " << contacts[i].phoneNumber << std::endl;
        std::cout << "Email: " << contacts[i].email << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

// Function to search for a contact by name
void searchContact(const std::vector<Contact>& contacts, const std::string& name) {
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Contact found:" << std::endl;
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email: " << contact.email << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

// Function to find a contact by name and return its index
int findContactIndex(const std::vector<Contact>& contacts, const std::string& name) {
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].name == name) {
            return static_cast<int>(i);
        }
    }
    return -1; // Contact not found
}

// Function to edit a contact by name
void editContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter the name of the contact to edit: ";
    std::getline(std::cin, name);

    int index = findContactIndex(contacts, name);
    if (index == -1) {
        std::cout << "Contact not found." << std::endl;
        return;
    }

    Contact& contact = contacts[index];
    std::cout << "Editing contact: " << contact.name << std::endl;

    std::cout << "Enter new phone number (leave blank to keep current): ";
    std::string newPhoneNumber;
    std::getline(std::cin, newPhoneNumber);
    if (!newPhoneNumber.empty()) {
        contact.phoneNumber = newPhoneNumber;
    }

    std::cout << "Enter new email (leave blank to keep current): ";
    std::string newEmail;
    std::getline(std::cin, newEmail);
    if (!newEmail.empty()) {
        contact.email = newEmail;
    }

    std::cout << "Contact updated." << std::endl;
}

// Function to delete a contact by name
void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter the name of the contact to delete: ";
    std::getline(std::cin, name);

    int index = findContactIndex(contacts, name);
    if (index == -1) {
        std::cout << "Contact not found." << std::endl;
        return;
    }

    contacts.erase(contacts.begin() + index);
    std::cout << "Contact deleted." << std::endl;
}

// Function to load contacts from a file
void loadContacts(std::vector<Contact>& contacts, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        contacts.push_back(Contact::deserialize(line));
    }
    file.close();
}

// Function to save contacts to a file
void saveContacts(const std::vector<Contact>& contacts, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    for (const auto& contact : contacts) {
        file << contact.serialize() << std::endl;
    }
    file.close();
}

int main() {
    std::vector<Contact> contacts;
    const std::string filename = "contacts.txt";
    loadContacts(contacts, filename);

    int choice;

    do {
        std::cout << "Contact Management System" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Edit Contact" << std::endl;
        std::cout << "5. Delete Contact" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3: {
                std::string name;
                std::cout << "Enter the name to search: ";
                std::getline(std::cin, name);
                searchContact(contacts, name);
                break;
            }
            case 4:
                editContact(contacts);
                break;
            case 5:
                deleteContact(contacts);
                break;
            case 6:
                saveContacts(contacts, filename);
                std::cout << "Exiting and saving contacts..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
