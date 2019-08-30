#ifndef EDITOR_OUTLINER_OUTLINER_ITEM_HPP_INCLUDE
#define EDITOR_OUTLINER_OUTLINER_ITEM_HPP_INCLUDE

#include <anton_stl/string_view.hpp>
#include <diagnostic_macros.hpp>
#include <ecs/entity.hpp>

ANTON_DISABLE_WARNINGS();
#include <QWidget>
ANTON_RESTORE_WARNINGS();

class QLabel;

class Outliner_Item: public QWidget {
    Q_OBJECT

public:
    explicit Outliner_Item(Entity, anton_stl::String_View, QWidget* parent = nullptr);
    Outliner_Item(Outliner_Item&&) noexcept;
    Outliner_Item& operator=(Outliner_Item&&) noexcept;
    ~Outliner_Item() override;

    Entity get_associated_entity() const;

private:
    QLabel* label;
    Entity entity;
};

#endif // !EDITOR_OUTLINER_OUTLINER_ITEM_HPP_INCLUDE
