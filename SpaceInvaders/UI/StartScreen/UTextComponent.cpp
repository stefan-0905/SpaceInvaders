
#include "../../Models/Utils.h"
#include "../../Config.h"
#include "UTextComponent.h"

UTextComponent::UTextComponent(const wchar_t* title)
{
	Title = title;

	TextBox.setFont(Config::GetFont());
	TextBox.setCharacterSize(CharacterSize);

}

void UTextComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
	TextBox.setString(Title);
	TextBox.setOrigin(TextBox.getGlobalBounds().width / 2, TextBox.getGlobalBounds().height / 2);
	TextBox.setPosition(PositionComponent->X(), PositionComponent->Y());
}

void UTextComponent::Tick(float DeltaTime)
{
	if (!ensure(PositionComponent)) return;
}

void UTextComponent::Draw(sf::RenderWindow& window)
{
	window.draw(TextBox);
}

void UTextComponent::SetColor(sf::Color color)
{
	TextBox.setFillColor(color);
}
