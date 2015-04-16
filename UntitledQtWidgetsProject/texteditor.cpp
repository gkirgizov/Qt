#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TextEditor)
{
	ui->setupUi(this);
	this->selectedIndex = -1;
	this->lengthOfSearched = 0;
}

TextEditor::~TextEditor()
{
	delete ui;
}

void TextEditor::selectText(int begin, int length)
{
	QTextCursor cursor = ui->textEdit->textCursor();
	cursor.setPosition(begin);
	cursor.setPosition(begin + length, QTextCursor::KeepAnchor);
	ui->textEdit->setTextCursor(cursor);
}

void TextEditor::searchInit()
{
	this->indexesBuffer.clear();
	ui->countOfFindedLineEdit->setText("0");
	this->selectedIndex = -1;
}

void TextEditor::on_fontComboBox_currentFontChanged(const QFont &f)
{
	ui->textEdit->setCurrentFont(f);
}

void TextEditor::on_fontSizeSpinBox_valueChanged(int newSize)
{
	ui->textEdit->setFontPointSize((qreal)newSize);
}

void TextEditor::on_searchLine_textChanged(const QString &searchedData)
{
	this->searchInit();

	if (!ui->searchLine->text().isEmpty())
	{
		int entranceIndex = ui->textEdit->toPlainText().indexOf(searchedData);

		if (entranceIndex >= 0)
		{
			int count = ui->textEdit->toPlainText().count(searchedData);
			ui->countOfFindedLineEdit->setText(QString::number(count));
			this->lengthOfSearched = searchedData.length();
			this->selectedIndex = 0;

			while (entranceIndex >= 0)
			{
				this->indexesBuffer.push_back(entranceIndex);
				entranceIndex = ui->textEdit->toPlainText().indexOf(searchedData, entranceIndex + 1);
			}

			this->selectText(this->indexesBuffer[0], this->lengthOfSearched);
		}
	}
}

void TextEditor::on_buttonNext_clicked()
{
	if (this->selectedIndex >= 0 &&
		this->selectedIndex < this->indexesBuffer.size() - 1)
	{
		++this->selectedIndex;
		this->selectText(this->indexesBuffer[this->selectedIndex], this->lengthOfSearched);
	}
}

void TextEditor::on_buttonPrev_clicked()
{
	if (this->selectedIndex > 0)
	{
		--this->selectedIndex;
		this->selectText(this->indexesBuffer[this->selectedIndex], this->lengthOfSearched);
	}
}

void TextEditor::on_buttonClear_clicked()
{
	this->searchInit();
	ui->searchLine->setText("");
}
