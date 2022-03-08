#include "textglinoutput.h"
namespace Onecard
{
void TextGlInOutput::startment()
{
    cout << "Made by Sayori1576" << endl;
    cout << "Onecard Game" << endl;
}
bool TextGlInOutput::quitment()
{

    cout << "게임을 끝내고 싶으시다면 Q를 누르시오. 아니라면 아무 키나 누르시오." << endl;
    std::string temp;
    cin >> temp;
    if (temp == "q" || temp == "Q")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int TextGlInOutput::inputplayernum()
{
    cout << "몇 명이서 할 건가요?" << endl;
    int num; //플레이어 수
    while (1)
    {

        cin >> num; //입력 받기
        if (!cin)
        {
            Default::cinnum();
        }
        else if ((num >= 7) || (num <= 1))
        {
            cout << "7명 이상은 이 게임을 할 수 없어요." << endl;
        }
        else
        {
            break;
        }
    }
    return num;
}
std::string TextGlInOutput::inputplayername()
{
    cout << "이름을 입력해 주세요" << endl;
    std::string temp; //이름
    cin >> temp;      //입력 받기

    return temp;
}
}