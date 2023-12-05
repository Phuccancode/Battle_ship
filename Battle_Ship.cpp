#include "main.h"
class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int distance_to(Point b) {
		if (this->x == b.x) return b.y - this->y + 1;
		else if (this->y == b.y) return b.x - this->x + 1;
		else return -1;
	}

};

class Player {
private:
	int ship2, ship3, ship4;
	int arr[10][10];
	int total;
	char mp[10][10];
public:
	
	Player() {
		ship2 = ship3 = ship4  = 0;
		total = 16;
		for (int i = 0; i < 10; i++) {
			for (int& x : arr[i]) x = 0;
			for (char& x : mp[i]) x = '-';
		}
	}
	bool fullSlot() {
		if (ship2 + ship3 + ship4 == 6) return true;
		return false;
	}
	bool checkOccupied(Point a, Point b) {
		if (a.x == b.x) {
			for (int i = a.y; i <= a.y; i++) {
				if (arr[a.x][i] == 1) return true;
			}
		}
		else {
			for (int i = a.x; i <= b.x; i++)
				if (arr[i][a.y] == 1) return true;
		}
		return false;
	}
	void initialShip();
	bool attackAt(int x, int y) {
		//Hack win begin 
		if (x == 29 && y == 6) {
			total = 0;
			return true;
		}
		//Hack win end

		if (arr[x][y] == 1) {
			cout << "Hit" << endl;
			if(mp[x][y]!='H') total--;
			mp[x][y] = 'H';
			displayMap();
			return true;
		}
		else {
			cout << "Miss" << endl;
			mp[x][y] = 'X';
			displayMap();
			return false;
		}
		return false;

	}
	void displayArr() {
		for (int i = 0; i < 10; i++) {
			for (int x : arr[i]) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	void displayMap() {
		for (int i = 0; i < 10; i++) {
			for (char x : mp[i]) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	int getTotal() {
		return total;
	}

};

void Player::initialShip()
{
	while(!fullSlot()){
	tryAgain:
		cout << "Choose your ship size: (2, 3, 4): ";
		int n; cin >> n;
		if (n == 2) {
			if (ship2 == 3) {
				cout << "Your ship type 2 is full, plz try another" << endl;
				goto tryAgain;
			}
			ship2++;
		}
		else if (n == 3) {
			if (ship3 == 2) {
				cout << "Your ship type 3 is full, plz try another" << endl;
				goto tryAgain;
			}
			ship3++;
		}
		else if (n == 4) {
			if (ship4 == 1) {
				cout << "Your ship type 4 is full, plz try another" << endl;
				goto tryAgain;
			}
			ship4++;
		}
		else {
			cout << "Invalid ship size, try again!" << endl;
			goto tryAgain;
		}

		bool valid = false;
		do {
			Occupied:
			cout << "Input the coordinates of ship head and rear: ";
			int x; cin >> x; int y; cin >> y;

			Point head(x, y);
			cin >> x; cin >> y;
			Point rear(x, y);
			if (head.distance_to(rear) != n) {
				valid = false;
				cout << "Invalid coordinates, input again plz: " << endl;
			}
			else {
				valid = true;
				if (checkOccupied(head, rear)) {
					cout << "This place was occupied, plz try again! " << endl;
					goto Occupied;
				}
				if (head.x == rear.x) {
					for (int i = head.y; i <= rear.y; i++) {
							arr[head.x][i] = 1;
					}
				}
				else {
					for (int i = head.x; i <= rear.x; i++) 
							arr[i][head.y] = 1;
				}
				displayArr();
			}
		} while (!valid);
	}
}