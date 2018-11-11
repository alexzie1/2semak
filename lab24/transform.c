#include "tree.h"
#include "transform.h"

int match_power(Tree *t)
{
    return (((*t) != NULL) && ((*t)->node.type == OPERATOR) && ((*t)->node.data.operator_name == '*')  && ((*t)->right->node.type == OPERATOR) && ((*t)->right->node.data.operator_name == '+')) ||
          ( ((*t) != NULL) && ((*t)->node.type == OPERATOR) && ((*t)->node.data.operator_name == '*') &&  ((*t)->left->node.type == OPERATOR)  && ((*t)->left->node.data.operator_name == '+'));
}

void transform_division(Tree *t)
{
    
    
    if ((*t)->node.data.operator_name == '*'  && (*t)->right->node.type == OPERATOR && (*t)->right->node.data.operator_name == '+') {
        
        Tree *tmp1, *tmp2, *tmp3;
        
        tmp1 = (*t)->left;
        tmp2 = (*t)->right->left;
        tmp3 = (*t)->right->right;
        
        (*t)->left = (Tree) malloc(sizeof(struct tree_node));
        (*t)->right = (Tree) malloc(sizeof(struct tree_node));
        
        (*t)->node.data.operator_name = '+';
        (*t)->left->node.type = OPERATOR;
        (*t)->left->node.data.operator_name = '*';
         (*t)->right->node.type = OPERATOR;
        (*t)->right->node.data.operator_name = '*';
        
        
        
        (*t)->left->left = tmp1;
        (*t)->left->right = tmp2;
        (*t)->right->left = tmp1;
        (*t)->right->right = tmp3;
        
    }
      if ((*t)->node.data.operator_name == '*'  && (*t)->left->node.type == OPERATOR && (*t)->left->node.data.operator_name == '+') {
        
        Tree *tmp1, *tmp2, *tmp3;
        
        tmp1 = (*t)->right;
        tmp2 = (*t)->left->left;
        tmp3 = (*t)->left->right;
      
        (*t)->left = (Tree) malloc(sizeof(struct tree_node));
        (*t)->right = (Tree) malloc(sizeof(struct tree_node));
        
      (*t)->node.data.operator_name = '+';
      (*t)->left->node.type = OPERATOR;
      (*t)->left->node.data.operator_name = '*';
      (*t)->right->node.type = OPERATOR;
      (*t)->right->node.data.operator_name = '*';
        
      
        
        (*t)->left->left = tmp1;
        (*t)->left->right = tmp2;
        (*t)->right->left = tmp1;
        (*t)->right->right = tmp3;
        
    }
}



void tree_transform(Tree *t)
{
    if ((*t) != NULL) {
        tree_transform(&((*t)->left));
        tree_transform(&((*t)->right));
        
        if (match_power(t)) {
            transform_division(t);
            tree_transform(&((*t)->left));
            tree_transform(&((*t)->right));
            
        }
    }
}


