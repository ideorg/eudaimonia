#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include <KSyntaxHighlighting/SyntaxHighlighter>
#include <KSyntaxHighlighting/Repository>

class PlainTextEdit : public QPlainTextEdit {
Q_OBJECT
    QString m_fileName;
public:
    explicit PlainTextEdit(const QString &fileName, QWidget *parent = nullptr);
    ~PlainTextEdit() override;
private:
    KSyntaxHighlighting::Repository *repository;
    KSyntaxHighlighting::SyntaxHighlighter highlighter;
};

#endif //PLAINTEXTEDIT_H
