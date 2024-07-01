#include <iostream>

using namespace std;

struct Film {
  string judul;
  int durasi, harga;

  Film *prev;
  Film *next;
};

Film *head, *tail, *cur, *del, *newNode, *afterNode;

void createFilm(string judul, int durasi, int harga) {
  head = new Film();
  head->judul = judul;
  head->durasi = durasi;
  head->harga = harga;
  head->prev = head;
  head->next = head;
  tail = head;
}

void addFirst(string judul, int durasi, int harga) {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    newNode = new Film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast(string judul, int durasi, int harga) {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    newNode = new Film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string judul, int durasi, int harga, int posisi) {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Position 1 is not a middle position" << endl;
    } else if (posisi < 1) {
      cout << "Position out of range" << endl;
    } else {
      newNode = new Film();
      newNode->judul = judul;
      newNode->durasi = durasi;
      newNode->harga = harga;

      cur = head;
      int nomor = 1;
      while (nomor < posisi - 1) {
        cur = cur->next;
        nomor++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

void removeFirst() {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

void removeLast() {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

void removeMiddle(int posisi) {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Position 1 is not a middle position" << endl;
    } else if (posisi < 1) {
      cout << "Position out of range" << endl;
    } else {
      cur = head;
      int nomor = 1;
      while (nomor < posisi - 1) {
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

void printFilms() {
  if (head == NULL) {
    cout << "Create the linked list first!!" << endl;
  } else {
    cout << "Film List: " << endl;
    cur = head;
    while (cur->next != head) {
      cout << "Title: " << cur->judul << endl;
      cout << "Duration: " << cur->durasi << " minutes" << endl;
      cout << "Price: Rp." << cur->harga << "\n" << endl;

      cur = cur->next;
    }
    cout << "Title: " << cur->judul << endl;
    cout << "Duration: " << cur->durasi << " minutes" << endl;
    cout << "Price: Rp." << cur->harga << "\n" << endl;
  }
}

int main() {
  createFilm("star wars", 120, 80000);
  printFilms();

  addFirst("the nun 3", 90, 35000);
  printFilms();

  addLast("warzone 3", 150, 100000);
  printFilms();

  addMiddle("battleship 3", 100, 70000, 2);
  printFilms();

  removeMiddle(2);
  printFilms();

  return 0;
}