#include <iostream>
using namespace std;

class Drob {
	int cel;
	int ch;
	int zn;

	void Simplify() {
		if (ch != 0) {
			int devider = abs(ch) >= zn ? zn : abs(ch);

			for (int i = devider; true; i--) {
				if (ch % i == 0 && zn % i == 0) {
					devider = i;
					break;
				}
			}
			ch /= devider;
			zn /= devider;

			cel += ch / zn;
			ch = ch % zn;

			if (ch < 0 && cel != 0) {
				ch *= -1;
				if (cel > 0) {
					cel *= -1;
				}
			}
		}
	}
public:
	Drob() : cel{ 0 }, ch{ 0 }, zn{ 1 } {}
	Drob(int cel, int ch, int zn) : cel{ cel }, ch{ ch }, zn{ 1 }{
		if (zn != 0)
			this->zn = zn;
		Simplify();
	}

	void Show() {
		cel == 0 ? cout << "" : cout << cel;
		ch == 0 ? cout << 0 : cout << "(" << ch << "/" << zn << ")";
	}

	Drob operator+(int number) {
		Drob res = *this;
		res.cel += number;
		res.Simplify();
		return res;
	}
	Drob operator+(const Drob& obj) {
		Drob res;
		res.cel = 0;
		res.zn = zn * obj.zn;
		res.ch = (ch < 0 || cel < 0 ? -1 : 1) * (abs(ch) + abs(cel) * zn) * obj.zn
			+ (obj.ch < 0 || obj.cel < 0 ? -1 : 1)*(abs(obj.ch) + abs(obj.cel) * obj.zn) * zn;
		res.Simplify();
		return res;
	}
	Drob operator-(const Drob& obj) {
		Drob res = *this;
		return res + (-obj);
	}

	Drob operator-() const {
		Drob res = *this;
		if (res.cel != 0) {
			res.cel *= -1;
		}
		else if (res.ch != 0) {
			res.ch *= -1;
		}
		return res;
	}

	void SetCh(int ch) {
		this->ch = ch;
	}
	void SetZn(int zn) {
		if (zn != 0)
			this->zn = zn;
	}
	int GetCh() const { return ch; }
	int GetZn() const { return zn; }
};

int main() {
	// +-*/ int 
	// +-*/ Drob

	// += -+ *= /+ int
	// += -+ *= /+ Drob

	// == != > >= < <= int
	// == != > >= < <= Drob

	// - унарный минус(меняет знак дроби)
	// ! унарная операция не(возвра true если дробь не ноль) 

	Drob dr1(1, 3, 4);
	dr1.Show(); cout << endl; // 1(3/4);

	Drob dr2;
	dr2 = dr1 + 2;
	dr2.Show(); cout << endl; // 3(3/4)

	Drob dr3;
	dr3 = dr1 + dr2; // 5(1/2)
	dr3.Show(); cout << endl;

	Drob dr4;
	dr4 = -dr3;
	dr4.Show(); cout << endl;

	Drob dr5(0, 0, 1);
	dr4 = -dr5;
	dr4.Show(); cout << endl;

	Drob dr6(-1, 1, 2);
	Drob dr7(1, 1, 4);

	dr7 = dr7 + dr6;
	dr7.Show();
	cin.get();
}