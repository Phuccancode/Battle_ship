#include "Battle_Ship.cpp"

int main() {
	Player p1, p2;
	cout << "Welcome to simple BattleShip game" << endl;
	cout << "Game is developed by Tran Hong Phuc aka Code King" << endl;
	cout << "Player 1 initial your battle:" << endl;
	p1.initialShip();
	system("cls");
	cout << "Player 2 initial your battle:" << endl;
	p2.initialShip();
	system("cls");
	while (p1.getTotal()>0 && p2.getTotal()>0) {
		bool hit = true;
		cout << "P1 turn!" << endl;
		p2.displayMap();
		while (hit) {
			cout << "Input coordinates to attack: ";
			int x; cin >> x; int y; cin >> y;
			hit = p2.attackAt(x, y);
			if (p2.getTotal() == 0) goto End;
			cout << "Remaining: " << p2.getTotal() << endl;
		}
		hit = true;
		cout << "P2 turn!" << endl;
		p1.displayMap();
		while (hit) {
			cout << "Input coordinates to attack: ";
			int x; cin >> x; int y; cin >> y;
			hit = p1.attackAt(x, y); 
			if (p1.getTotal() == 0) goto End;
			cout << "Remaining: " << p1.getTotal() << endl;
		}

	}
	End:
	if (p1.getTotal() == 0) cout << "P2 win. Congratulation!";
	else cout << "P1 win. Congratulation!";
	return 0;
}

// 2 0 0 0 1 2 0 2 0 3 2 0 4 0 5 3 0 6 0 8 3 0 9 2 9 4 1 5 1 8
// 0 0 0 1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 1 5 1 6 1 7 1 8 1 9 