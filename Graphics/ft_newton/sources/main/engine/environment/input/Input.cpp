#include "Input.h"

#include "engine/tools/debug/Debug.h"
#include "engine/environment/window/Window.h"

using namespace engine;

void Input::initialize()
{
	_keys[A] = State::None;
	_keys[B] = State::None;
	_keys[C] = State::None;
	_keys[D] = State::None;
	_keys[E] = State::None;
	_keys[F] = State::None;
	_keys[G] = State::None;
	_keys[H] = State::None;
	_keys[I] = State::None;
	_keys[J] = State::None;
	_keys[K] = State::None;
	_keys[L] = State::None;
	_keys[M] = State::None;
	_keys[N] = State::None;
	_keys[O] = State::None;
	_keys[P] = State::None;
	_keys[Q] = State::None;
	_keys[R] = State::None;
	_keys[S] = State::None;
	_keys[T] = State::None;
	_keys[U] = State::None;
	_keys[V] = State::None;
	_keys[W] = State::None;
	_keys[X] = State::None;
	_keys[Y] = State::None;
	_keys[Z] = State::None;
	_keys[One] = State::None;
	_keys[Two] = State::None;
	_keys[Three] = State::None;
	_keys[Four] = State::None;
	_keys[Five] = State::None;
	_keys[Six] = State::None;
	_keys[Seven] = State::None;
	_keys[Eight] = State::None;
	_keys[Nine] = State::None;
	_keys[Ten] = State::None;
	_keys[Escape] = State::None;
	_keys[Enter] = State::None;
	_keys[Space] = State::None;
	_keys[Shift] = State::None;
	_keys[Command] = State::None;
	_keys[Left] = State::None;
	_keys[Up] = State::None;
	_keys[Right] = State::None;
	_keys[Down] = State::None;
	_keys[Plus] = State::None;
	_keys[Minus] = State::None;
	_keys[LeftMouse] = State::None;
	_keys[RightMouse] = State::None;
}

void Input::refresh()
{
	refreshKeys();
	refreshMousePosition();
}

bool Input::isPressed(Key key)
{
	return getStateOfKey(key) == State::Pressed;
}

bool Input::isReleased(Key key)
{
	return getStateOfKey(key) == State::Released;
}

bool Input::isHeld(Key key)
{
	return getStateOfKey(key) == State::Held;
}

bool Input::isPressedOrHeld(Key key)
{
	const auto state = getStateOfKey(key);
	return state == State::Pressed or state == State::Held;
}

Input::State Input::getStateOfKey(Key key)
{
	const auto iterator = _keys.find(key);

	if (iterator == _keys.end())
	{
		Debug::logWarning("Input", string("Key '") + to_string(key) + "' not found");
		return None;
	}

	return iterator->second;
}

void Input::refreshKeys()
{
	for (auto &[key, state] : _keys)
	{
		if (not tryProcessNewState(key, state))
			processOldState(state);
	}
}

bool Input::tryProcessNewState(Key key, State &state)
{
	const int glfwState = getGlfwState(key);

	if (glfwState == GLFW_PRESS and state != Pressed and state != Held)
	{
		state = Pressed;
		return true;
	}
	else if (glfwState == GLFW_RELEASE and (state == Pressed or state == Held))
	{
		state = Released;
		return true;
	}

	return false;
}

int Input::getGlfwState(Key key)
{
	return isKeyBelongsToMouse(key) ? Window::getMouseKeyState(key) : Window::getKeyboardKeyState(key);
}

bool Input::isKeyBelongsToMouse(Key key)
{
	return key == LeftMouse or key == RightMouse;
}

void Input::processOldState(State &state)
{
	if (state == State::Pressed)
		state = State::Held;
	else if (state == State::Released)
		state = State::None;
}

void Input::refreshMousePosition()
{
	static bool firstCall = true;

	const auto mousePosition = Window::getMousePosition();

	if (firstCall)
	{
		firstCall = false;

		_lastMousePosition = mousePosition;
		_currentMousePosition = mousePosition;
	}
	else
	{
		_lastMousePosition = _currentMousePosition;
		_currentMousePosition = mousePosition;
	}
}