#include <iostream>
#include <fstream>

/*class AbstractFactory
{
protected:
    std::string file;
public:
    virtual ~AbstractFactory();
    virtual void make_chapter(std::string caption) const = 0;
    virtual void make_text(std::string text, std::string style = "common") const = 0;
    virtual void make_image(std::string url) const = 0;
    virtual void make_ref(std::string std, std::string ref) const = 0;
    //virtual void make_italic(std::string text);
    //virtual void make_bold(std::string text);
    virtual void save (std::string name) const = 0;
};

class MDfile : public::AbstractFactory
{
public:
    void make_chapter(std::string caption)
    {
        file += "#" + caption + "\n";
    }
    void make_text(std::string text, std::string style = "common")
    {
        if (style == "i") file += "*" + text + "*";
        else if (style == "b") file += "**" + text + "**";
        else if (style == "ib" || style == "bi") file += "***" + text + "***";
        else file += text;
    }
    void make_image(std::string png, std::string url = "")
    {
        if (url == "")
        file += "![Couldn't load the image](" + png + ")";
        else file += "[![Couldn't load the image](" + png + ")](" + url + ")";
    }
    void make_ref(std::string std, std::string ref)
    {
        file += "[" + std + "]";
        file = "[" + std + "]: " + ref + "\n" + file;
    }
    void save (std::string name)
    {
      std::ofstream fout(name);
      fout << file;
      file = "";
    }
};
*/

class Chapter //Абстрактный продукт "Заголовок"
{
public:
  virtual ~Chapter(){};
  virtual void make_chapter(std::string caption, std::string filename = "MyFile.txt") = 0;
};

class MD_Chapter : public:: Chapter //Конкретный продукт "Заголовок Markdown"
{
public:
  void make_chapter(std::string caption, std::string filename = "MyFile.txt")
  {
    std::ofstream fout(filename, std::ofstream::out | std::ofstream::app);
    fout << "#" + caption + "\n";
    fout.close();
  }
};

class Text //Абстрактный продукт "Текст"
{
public:
  virtual ~Text(){};
  virtual void make_text(std::string text, std::string style = "common", std::string filename = "MyFile.txt") = 0;
};

class MD_Text : public::Text //Конкретный продукт "Текст Markdown"
{
public:
 void make_text(std::string text, std::string style = "common", std::string filename = "MyFile.txt")
    {
      std::ofstream fout(filename, std::ofstream::out | std::ofstream::app);
        if (style == "i") fout << "*" + text + "*";
        else if (style == "b") fout << "**" + text + "**";
        else if (style == "ib" || style == "bi") fout << "***" + text + "***";
        else fout << text;
        fout.close();
    }

};

class Image //Абстрактный продукт "Картинка"
{
public:
 virtual ~Image(){};
 virtual void make_image(std::string png, std::string url, std::string filename = "MyFile.txt") = 0;
};

class MD_Image : public::Image //Конкретный продукт "Картинка Markdown"
{
public:
  void make_image(std::string png, std::string url = "", std::string filename = "MyFile.txt")
    {
      std::ofstream fout(filename, std::ofstream::out | std::ofstream::app);
        if (url == "")
        {fout << "![Couldn't load the image](" + png + ") ";}
        else {fout << "[![Couldn't load the image](" + png + ")](" + url + ") ";}
      fout.close();
    }
};

class Reference //Абстрактный продукт "Ссылка"
{
public:
 virtual ~Reference(){};
 virtual void make_ref(std::string std, std::string ref, std::string filename = "MyFile.txt") = 0;
};

class MD_Reference : public::Reference //Конкретный продукт "Ссылка Markdown"
{
public:
  void make_ref(std::string std, std::string ref, std::string filename = "MyFile.txt")
    {
      std::ofstream fout(filename, std::ofstream::out | std::ofstream::app);
        fout << "[" + std + "](" + ref + ") "; 
      fout.close();
    }
};

class AbstractFactory //Абстрактная фабрика
{
 public:
  virtual Chapter *CreateChapter() const = 0;
  virtual Text *CreateText() const = 0;
  virtual Image *CreateImage() const = 0;
  virtual Reference *CreateReference() const = 0;
};

class MD_File : public::AbstractFactory //Конкретная фабрика "Markdown"
{
public:
  Chapter *CreateChapter() const override {return new MD_Chapter();};
  Text *CreateText() const override {return new MD_Text();};
  Image *CreateImage() const override {return new MD_Image();};
  Reference *CreateReference() const override {return new MD_Reference();};
};