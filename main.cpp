#include <iostream>

using namespace std;


  struct ListNode
    {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

  class Solution
  {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
      {
          int perebor=0;
          while(l1->val!=0 && l2->val!=0)
          {
              if ((l1->val+l2->val+perebor)>9)
              {
                  l1->val=(l1->val+l2->val-10+perebor);
                  perebor=1;
              }
              else
              {
                  l1->val=(l1->val+l2->val+perebor);
                  perebor=0;
              }
              l1++;
              l2++;
          }
          return l1;
      }
  };

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
      int perebor=0;
      int count=1;
      int count_1=1;
      int count_2=1;
      ListNode *lp1,*lp2;
      lp1=l1;
      lp2=l2;
      ListNode *lpp1,*lpp2;
      lpp1=l1;
      lpp2=l2;
      ListNode *lppp1,*lppp2;
      lppp1=l1;
      lppp2=l2;
      ListNode lsn(1);
      (&lsn)->next=nullptr;

      while (lp1->next != nullptr)
      {
          count_1++;
          lp1=lp1->next;
      }
      while (lp2->next != nullptr)
      {
          count_2++;
          lp2=lp2->next;
      }
      if (count_1>=count_2)
      {
          while(l1->next != nullptr)
          {

              if (count>count_2)
              {
                  if ((l1->val+perebor)>9)
                  {
                      l1->val=(l1->val-10+perebor);
                      perebor=1;
                  }
                  else
                  {
                      l1->val=(l1->val+perebor);
                      perebor=0;
                  }
                  count++;
                  l1=l1->next;
              }
              else
              {
                  if ((l1->val+l2->val+perebor)>9)
                  {
                      l1->val=(l1->val+l2->val-10+perebor);
                      perebor=1;
                  }
                  else
                  {
                      l1->val=(l1->val+l2->val+perebor);
                      perebor=0;
                  }
                  l1=l1->next;
                  l2=l2->next;
                  count++;
              }
          }

          if (count>count_2)
          {
              if ((l1->val+perebor)>9)
              {
                  l1->val=(l1->val-10+perebor);
                  perebor=1;
              }
              else
              {
                  l1->val=(l1->val+perebor);
                  perebor=0;
              }
              count++;
              if (perebor==1)
              {
                  lppp2->val=1;
                  lppp2->next=nullptr;
                  l1->next = lppp2;
              }
          }
          else
          {
              if ((l1->val+l2->val+perebor)>9)
              {
                  l1->val=(l1->val+l2->val-10+perebor);
                  perebor=1;
              }
              else
              {
                  l1->val=(l1->val+l2->val+perebor);
                  perebor=0;
              }
              count++;
              if (perebor==1)
              {
                  lppp2->val=1;
                  lppp2->next=nullptr;
                  l1->next = lppp2;
              }
          }

          return lpp1;
      }
      else
      {
          while(l2->next != nullptr)
          {

              if (count>count_1)
              {
                  if ((l2->val+perebor)>9)
                  {
                      l2->val=(l2->val-10+perebor);
                      perebor=1;
                  }
                  else
                  {
                      l2->val=(l2->val+perebor);
                      perebor=0;
                  }
                  count++;
                  l2=l2->next;;
              }
              else
              {
                  if ((l1->val+l2->val+perebor)>9)
                  {
                      l2->val=(l1->val+l2->val-10+perebor);
                      perebor=1;
                  }
                  else
                  {
                      l2->val=(l1->val+l2->val+perebor);
                      perebor=0;
                  }
                  l1=l1->next;;
                  l2=l2->next;;
                  count++;
              }
          }

          if (count>count_1)
          {
              if ((l2->val+perebor)>9)
              {
                  l2->val=(l2->val-10+perebor);
                  perebor=1;
              }
              else
              {
                  l2->val=(l2->val+perebor);
                  perebor=0;
              }
              count++;
              if (perebor==1)
              {
                  lppp1->val=1;
                  lppp1->next=nullptr;
                  l2->next = lppp1;
              }
          }
          else
          {
              if ((l1->val+l2->val+perebor)>9)
              {
                  l2->val=(l1->val+l2->val-10+perebor);
                  perebor=1;
              }
              else
              {
                  l2->val=(l1->val+l2->val+perebor);
                  perebor=0;
              }
              if (perebor==1)
              {
                  lppp1->val=1;
                  lppp1->next=nullptr;
                  l2->next = lppp1;
              }
              count++;
          }

          return lpp2;
      }


  }

int main()
{
    ListNode *ptr;
    ListNode l1_7(9);
    ListNode l1_6(9);
    ListNode l1_5(9);
    ListNode l1_4(9);
    ListNode l1_3(9);
    ListNode l1_2(9);
    ListNode l1_1(9);
    l1_1.next = & l1_2;
    l1_2.next = & l1_3;
    l1_3.next = & l1_4;
    l1_4.next = & l1_5;
    l1_5.next = & l1_6;
    l1_6.next = & l1_7;
    l1_7.next = nullptr;

    ListNode *pte;
    ListNode l2_4(9);
    ListNode l2_3(9);
    ListNode l2_2(9);
    ListNode l2_1(9);
    l2_1.next = & l2_2;
    l2_2.next = & l2_3;
    l2_3.next = & l2_4;
    l2_4.next = nullptr;

    ListNode * l3;
    l3=addTwoNumbers(&l1_1,&l2_1);
    for (int i=0; i<8; i++)
    {
        cout<<l3->val<<"  ";
        l3=l3->next;
    }
    l3=l3->next;
    cout<<l3->val<<"  ";
    return 0;
}
