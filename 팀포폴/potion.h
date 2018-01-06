#pragma once
#include "objects.h"
	class potion : public objects
	{
	public:
			potion();
		~potion();

		HRESULT init(int x, int y);
			void update();
			void render();
	};

