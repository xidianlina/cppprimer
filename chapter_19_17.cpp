#include <string>

class Screen
{
public:
	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();

	using Action = Screen& (Screen::*)();
	enum Directions{HOME,FORWARD,BACK,UP,DOWN};
	Screen& move(Directions);
private:
	static Action Menu[];
};

Screen& Screen::move(Directions cm)
{
	return (this->*Menu[cm])();
}

Screen::Action Screen::Menu[] =
{
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};