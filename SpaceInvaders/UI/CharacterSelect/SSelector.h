#pragma once

#include "../SWidget.h"

enum class SelectState;

class SSelector : public SWidget
{
public:
	SSelector();

	const SelectState& GetState() const;
};