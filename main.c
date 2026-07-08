#include <stdio.h>
#include <string.h>

#define QUESTION(x)(x==1 ? 1:0)// 2択質問の際、1なら実行

void ToDo_input();      //リストを追加
void ToDo_update();     //リストを更新
void ToDo_delete();     //リストを削除
void All_list_print();  //リストを一覧表示
int ToDo_explorer();    //リストを検索
int blank_explorer();   //空リストを探索
void ToDo_print(int choice_index); //リストを確認表示

//ToDOリストを格納
typedef struct ToDo_t
{
    char to_do[100];    //to_do名
    int month,date;     //期限日
}ToDo_t;
ToDo_t ToDo_list[100];

//空リスト検索関数----------------------
int blank_explorer()
{
    int blank_index = 0;    //初期化
    //ToDoの中身がNULLの要素を探索
    while(strcmp(ToDo_list[blank_index].to_do,"") != 0) blank_index++;
    return blank_index;     //空の要素番号を返す
}
//リスト検索関数------------------------
int ToDo_explorer()
{
    int select_index; //管理番号
    printf("何番のリスト？:");
    //対象の数字を入力して表示
    if(scanf("%d",&select_index) ==1){
        puts("入力エラー");
        return 0;
    }else if (select_index < 0 && select_index >=100 ){
        puts("恐れ入りますが、数字を再度入力してください");
        return 0;
    }
    printf("%d\n番ですね！\n",select_index);
    ToDo_print(select_index);
    return select_index;
}
//リスト確認表示関数------------------------
void ToDo_print(int choice_index)
{
    printf("管理番号：%d\n",choice_index);
    printf("ToDo：%s\n",ToDo_list[choice_index].to_do);
    printf("期限日：%d\%dまで\n",ToDo_list[choice_index].month,ToDo_list[choice_index].date);
}
//リスト追加関数------------------------
void ToDo_input()
{
    int index;  //空リスト番号
    index = blank_explorer();
    //ToDoを入力
    printf("入力ですね！\nToDoは何？:");
    scanf("%s",ToDo_list[index].to_do);
    //期限日を入力
    printf("いつまでにやる？:") ;
    scanf("%d/%d",&ToDo_list[index].month,&ToDo_list[index].date);
    //確認
    puts("保存完了、以下のように記録しました！");
    ToDo_print(index);
    printf("機能を終了します");  

}
//リスト更新関数------------------------
void ToDo_update()
{
    int index,answer;  //リスト番号、答え
    char temp[100];//一時保存

    index = ToDo_explorer();//更新したい番号を選択
    //ToDoを更新
    puts("ToDoを変更しますか？");
    printf("本当にするなら1を入力 :");
    if(scanf("%d",&answer) !=1){            //入力の正誤をチェック
        puts("正しい数値を入力してください");
    }
    if(QUESTION(answer)){                   //answerが1なら更新
        scanf("%s",temp);
        strcpy(ToDo_list[index].to_do,temp);
    }
    //期限日を更新
    puts("期限日を変更しますか？");
    printf("本当にするなら1を入力 :");
    if(scanf("%d",&answer) !=1){            //入力の正誤をチェック
        puts("正しい数値を入力してください");
    }
    if(QUESTION(answer)){                   //answerが1なら更新
        scanf("%d/%d",
            &ToDo_list[index].month,&ToDo_list[index].date);
    }
    //確認
    puts("保存完了、以下のように記録しました！");
    ToDo_print(index);
    puts("機能を終了します");

    
}
//リスト削除関数------------------------
void ToDo_delete()
{
    int index,answer;  //リスト番号、答え

    index = ToDo_explorer();

    puts("削除しますか？");  
    printf("本当にするなら1を入力 :");

    if(scanf("%d",&answer) !=1){            //入力の正誤をチェック
        puts("正しい数値を入力してください");
    }

    if(QUESTION(answer)){                   //answerが1なら削除（NULLを代入）
        strcpy(ToDo_list[index].to_do,"");
        ToDo_list[index].month = 0;
        ToDo_list[index].date = 0;
    }

    puts("機能を終了します");

}
//リスト一覧表関数----------------------
void All_list_print()
{
    int i = 0; //ループ用
    puts("----リスト一覧----");
    //ToDoの中身を表示
    for(int i = 0;i<100;i++) {
        if (strcmp(ToDo_list[i].to_do,"") != 0)
        {
            printf("番号:%-3d. %s\n",i+1,ToDo_list[i].to_do);
            printf("%d/%dまで\n",ToDo_list[i].month,ToDo_list[i].date);
            puts("");
        }
    }
}

//main---------------------------------
int main(int argv,char** argc)
{
    int func_No = 0;    //機能番号

    puts("～Todoリスト～");
    puts("何をしますか？\n下のリストから数字を選んで！");  
    puts("[新規追加:1 / 一覧表示:2 / 確認:3 / 更新:4 / 削除:5]");
    printf("やるのはこれ→");    
    if(scanf("%d",&func_No)!=1){
        puts("恐れ入りますが、再度リストから数字をお選びください");
        return 1;
    }

    switch (func_No)
    {
        case 1: //リストの追加
            ToDo_input();      break;
        case 2: //リストの一覧表示
            All_list_print();  break;
        case 3: //リストの検索
            ToDo_explorer();   break;
        case 4: //リストの更新
            ToDo_update();     break;
        case 5: //リストの削除
            ToDo_delete();     break;
    
    default:
        puts("エラー！！");
        puts("恐れ入りますが、再度リストから数字をお選びください");
        break;
    }

    return 0;
}
