#include <KSyntaxHighlighting/Definition>
#include <Theme>
#include "PlainTextEdit.h"

PlainTextEdit::PlainTextEdit(const QString &fileName, QWidget *parent)
    : m_fileName(fileName),
      QPlainTextEdit(parent),
      highlighter(document())
{
    repository = new KSyntaxHighlighting::Repository();
    auto def = repository->definitionForFileName(m_fileName);
    highlighter.setDefinition(def);
    auto theme = repository->defaultTheme(KSyntaxHighlighting::Repository::LightTheme);
    highlighter.setTheme(theme);
}
PlainTextEdit::~PlainTextEdit() {
    delete repository;
}
