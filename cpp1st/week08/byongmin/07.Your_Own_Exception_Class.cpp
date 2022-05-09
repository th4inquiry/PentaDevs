#include <iostream>
#include <exception>

using namespace std;

class FileError : public exception
{
public:
    FileError() = delete;
    FileError(string_view fileName) : myFileName(fileName) {}

    virtual char const* what() const noexcept override
    {
        return myMessage.c_str();
    }

    string getFileName() const noexcept 
    { 
        return myFileName;
    }

protected:
    void setMessage(string message)
    {
        myMessage = message;
    }

private:
    string myFileName;
    string myMessage;
};

class FileOpenError : public FileError
{
public:
    FileOpenError(string fileName) : FileError(fileName)
    {
        setMessage("Unable to open "s + fileName.data());
    }
};

int main()
{
    try
    {
        throw FileOpenError("sample.txt");
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}