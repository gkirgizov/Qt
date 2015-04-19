#pragma once

#include <QDialog>
#include <QList>

namespace Ui {
	class TextEditor;
}

class TextEditor : public QDialog
{
	Q_OBJECT

public:
	explicit TextEditor(QWidget *parent = 0);
	~TextEditor();

private slots:
	void on_fontComboBox_currentFontChanged(const QFont &f);

	void on_fontSizeSpinBox_valueChanged(int newSize);

	void on_searchLine_textChanged(const QString &searchedData);

	void on_buttonNext_clicked();

	void on_buttonPrev_clicked();

	void on_buttonClear_clicked();

private:
	Ui::TextEditor *ui;

	QList<int> indexesBuffer;
	int selectedIndex;

	int lengthOfSearched;

	void selectText(int begin, int length);

	void searchInit();
};
