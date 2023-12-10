#include "Factory.h"
#include <string>

/// @brief Функция для записи в текстовый файл
/// @param factory Тип документа
void Write(AbstractFactory &factory)
{
    
    std::string a; //Переменная для определения операции
    while (a != "End" && a != "5")
    {
    std::cout << "<Chapter>, <Text>, <Image>, <Reference> or <End>?\n";
    std::getline(std::cin, a);
    if (a == "Chapter" || a == "1")
    {
        std::string caption; //Заголовок
        std::getline(std::cin, caption);
        Chapter *New_Chapter = factory.CreateChapter();
        New_Chapter->make_chapter(caption);
        delete New_Chapter;
    }
    else if (a == "Text" || a == "2")
    {
        std::string text; //Текст
        std::getline(std::cin, text);
        Text *New_Text = factory.CreateText();
        New_Text->make_text(text);
    }
    else if (a == "Image" || a == "3")
    {
        std::string png, url; //Картинка, ссылка
        std::getline(std::cin, png);
        std::getline(std::cin, url);
        Image *New_Image = factory.CreateImage();
        New_Image->make_image(png, url);
    }
    else if (a == "Reference" || a == "4")
    {
        std::string text, url; //Текст, ссылка
        std::getline(std::cin, text);
        std::getline(std::cin, url);
        Reference *New_Reference = factory.CreateReference();
        New_Reference->make_ref(text, url);
    }
    }


}

int main()
{
    std::cout << "Enter document type\n<Markdown>\n";
    std::string a; 
    std::getline(std::cin, a);
    if (a == "MD" || a == "Markdown" || a == "1")
    {
    MD_File *f1 = new MD_File(); //Вызов конкретной фабрики Markdown
    std::ofstream fout("MyFile.txt");
    fout << ""; 
    fout.close();
    Write(*f1);
    delete f1;
    }

    return 0;
}
