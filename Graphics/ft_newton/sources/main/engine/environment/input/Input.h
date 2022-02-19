#pragma once

#include "engine/environment/Environment.h"
#include "engine/tools/Tools.h"

#include "engine/tools/external/std/unordered_map.h"
#include "engine/tools/external/OpenGL.h"
#include "engine/tools/external/glm/glm.h"

class engine::Input
{
public :

	enum Key : int
	{
		A = GLFW_KEY_A,
		B = GLFW_KEY_B,
		C = GLFW_KEY_C,
		D = GLFW_KEY_D,
		E = GLFW_KEY_E,
		F = GLFW_KEY_F,
		G = GLFW_KEY_G,
		H = GLFW_KEY_H,
		I = GLFW_KEY_I,
		J = GLFW_KEY_J,
		K = GLFW_KEY_K,
		L = GLFW_KEY_L,
		M = GLFW_KEY_M,
		N = GLFW_KEY_N,
		O = GLFW_KEY_O,
		P = GLFW_KEY_P,
		Q = GLFW_KEY_Q,
		R = GLFW_KEY_R,
		S = GLFW_KEY_S,
		T = GLFW_KEY_T,
		U = GLFW_KEY_U,
		V = GLFW_KEY_V,
		W = GLFW_KEY_W,
		X = GLFW_KEY_X,
		Y = GLFW_KEY_Y,
		Z = GLFW_KEY_Z,
		One = GLFW_KEY_1,
		Two = GLFW_KEY_2,
		Three = GLFW_KEY_3,
		Four = GLFW_KEY_4,
		Five = GLFW_KEY_5,
		Six = GLFW_KEY_6,
		Seven = GLFW_KEY_7,
		Eight = GLFW_KEY_8,
		Nine = GLFW_KEY_9,
		Ten = GLFW_KEY_0,
		Escape = GLFW_KEY_ESCAPE,
		Enter = GLFW_KEY_ENTER,
		Space = GLFW_KEY_SPACE,
		Shift = GLFW_KEY_LEFT_SHIFT,
		Command = GLFW_KEY_LEFT_SUPER,
		Left = GLFW_KEY_LEFT,
		Up = GLFW_KEY_UP,
		Right = GLFW_KEY_RIGHT,
		Down = GLFW_KEY_DOWN,
		Plus = GLFW_KEY_EQUAL,
		Minus = GLFW_KEY_MINUS,
		LeftMouse = GLFW_MOUSE_BUTTON_LEFT,
		RightMouse = GLFW_MOUSE_BUTTON_RIGHT
	};

	Input() = delete;
	~Input() = delete;

	static void initialize();

	static void refresh();

	inline static vec2 getMouseOffset()
	{
		return _currentMousePosition - _lastMousePosition;
	}

	inline static vec2 getLastMousePosition()
	{
		return _lastMousePosition;
	}

	inline static vec2 getCurrentMousePosition()
	{
		return _currentMousePosition;
	}

	static bool isPressed(Key key);
	static bool isReleased(Key key);
	static bool isHeld(Key key);
	static bool isPressedOrHeld(Key key);

private :

	enum State : int
	{
		None = 0,
		Pressed,
		Released,
		Held
	};

	static inline unordered_map<Key, State> _keys;

	static State getStateOfKey(Key key);

	static void refreshKeys();

	static bool tryProcessNewState(Key key, State &state);
	static int getGlfwState(Key key);
	static bool isKeyBelongsToMouse(Key key);

	static void processOldState(State &state);

	static inline vec2 _lastMousePosition;
	static inline vec2 _currentMousePosition;

	static void refreshMousePosition();
};