#include "TitleBar.hpp"
#include "Button.hpp"
#include "../Window.hpp"

namespace psychic_ui {

    TitleBar::TitleBar() :
        Div() {
        setTag("TitleBar");
        _defaultStyle
            ->set(flexDirection, "row")
            ->set(shrink, 0);

        add<Button>(
            "Close", [this]() {
                window()->close();
            }
        )->addClassName("close");

        add<Button>(
            "Minimize", [this]() {
                window()->toggleMinimized();
            }
        )->addClassName("minimize");

        add<Button>(
            "Maximize", [this]() {
                window()->toggleFullscreen();
            }
        )->addClassName("maximize");

        _label = add<Label>();
        _label->addClassName("title");

        onMouseDown(
            [this](int /*mouseX*/, int /*mouseY*/, int /*button*/, Mod /*modifiers*/) {
                window()->startDrag();
            }
        );

        onMouseUp(
            [this](int /*mouseX*/, int /*mouseY*/, int /*button*/, Mod /*modifiers*/) {
                window()->stopDrag();
            }
        );
    };

    void TitleBar::addedToRender() {
        Div::addedToRender();
        // TODO: Allow updates to title
        _label->setText(window()->getTitle());
    }

}
