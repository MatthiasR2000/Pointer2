#include <iostream>
using namespace std;

struct ListenElement {
    int inhalt;
    ListenElement* next; // Zeiger auf das nächste Element
};

void einfuegen(ListenElement*& head, int wert);
void ausgeben(ListenElement* head);
void listeFreigeben(ListenElement*& head);

int main() {
    ListenElement* head = nullptr; // Kopf der Liste ist sehr wichtig, ohne ihn verlieren wir Zugriff

    einfuegen(head, 13);
    einfuegen(head, 19);
    einfuegen(head, 17);

    cout << "Liste: ";
    ausgeben(head);

    // Speicher freigeben
    listeFreigeben(head);
    return 0;
}

// Funktion zum Hinzufügen eines Elements am Ende der Liste
void einfuegen(ListenElement*& head, int wert) {
    ListenElement* neuesElement = new ListenElement; // Ein neues Element wird erstellt
    neuesElement->inhalt = wert; // Dem neuen Element wird der übergebene Wert zugewiesen
    neuesElement->next = nullptr; // Das neue Element wird als letztes Element markiert (zeigt auf nullptr)

    if (head == nullptr) { // Fall 1: Liste ist leer
        head = neuesElement; // Das neue Element wird zum Kopf der Liste
    }
    else { // Fall 2: Liste ist nicht leer
        ListenElement* tmp = head; // Temporärer Zeiger wird angelegt, um die Liste durchzugehen und um nicht den tatsächlichen head auf nullptr zu setzen was Zugriffsverlust bedeutet
        while (tmp->next != nullptr) { // Wir iterieren bis zum letzten Element der Liste
            tmp = tmp->next; // Gehe zum nächsten Element
        }
        tmp->next = neuesElement; // Hänge das neue Element an das Ende der Liste
    }
}

// Funktion zum Ausgeben der Liste
void ausgeben(ListenElement* head) {
    ListenElement* tmp = head; // Temporärer Zeiger wird angelegt, um die Liste durchzugehen und um nicht den tatsächlichen head auf nullptr zu setzen was Zugriffsverlust bedeutet
    while (tmp != nullptr) { // Solange wir nicht das Ende der Liste erreicht haben
        cout << tmp->inhalt << " -> "; // Gebe den Inhalt des aktuellen Elements aus
        tmp = tmp->next; // Gehe zum nächsten Element
    }
    cout << "NULL" << endl; // Ende der Liste erreicht
}

// Speicher muss am Ende freigegeben werden!!!
void listeFreigeben(ListenElement*& head) {
    // Solange wir nicht am Ende angekommen sind (head == nullptr), folgen wir der Zeigerverkettung und löschen die Elemente
    while (head != nullptr) {
        ListenElement* tmp = head; // Temporärer Zeiger auf das aktuelle Element
        head = head->next; // Gehe zum nächsten Element
        delete tmp; // Lösche das aktuelle Element
    }
}
