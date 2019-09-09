#ifndef EDITOR_LOG_VIEWER_LOG_VIEWER_HPP_INCLUDE
#define EDITOR_LOG_VIEWER_LOG_VIEWER_HPP_INCLUDE

#include <anton_stl/string_view.hpp>
#include <anton_stl/vector.hpp>
#include <logging.hpp>

#include <diagnostic_macros.hpp>
ANTON_DISABLE_WARNINGS();
#include <QWidget>
ANTON_RESTORE_WARNINGS();

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;

class Log_Message: public QWidget {
public:
    Log_Message(anton_engine::Log_Message_Severity, anton_stl::String_View, QWidget* parent = nullptr);
    Log_Message(Log_Message&&) noexcept;
    Log_Message& operator=(Log_Message&&) noexcept;
    ~Log_Message() override;

private:
    QHBoxLayout* layout = nullptr;
    QLabel* message = nullptr;
};

class Log_Viewer: public QWidget {
public:
    Log_Viewer(QWidget* parent = nullptr);
    Log_Viewer(Log_Viewer&&) noexcept;
    Log_Viewer& operator=(Log_Viewer&&) noexcept;
    ~Log_Viewer() override;

    void add_message(anton_engine::Log_Message_Severity, anton_stl::String_View time, anton_stl::String_View message);
    void remove_all_messages();

private:
    anton_stl::Vector<Log_Message> messages;
    QVBoxLayout* layout = nullptr;
    QScrollArea* scroll_area = nullptr;
    QWidget* content = nullptr;
    QVBoxLayout* content_layout = nullptr;
    QWidget* message_list = nullptr;
    QVBoxLayout* message_list_layout = nullptr;
};

#endif // !EDITOR_LOG_VIEWER_LOG_VIEWER_HPP_INCLUDE