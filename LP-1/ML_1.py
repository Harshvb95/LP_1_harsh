#!/usr/bin/env python
# coding: utf-8

# In[26]:


import pandas as pd
pd.read_csv(r"C:\Users\DELL\Downloads\Heart.csv")


# # Storing Dataset in variable 'data'

# In[27]:


data = pd.read_csv(r"C:\Users\DELL\Downloads\Heart.csv")


# # Displaying Data

# In[4]:


print(data)


# # Displaying first 5 rows of database 

# In[5]:


print(data.head(5))


# # Displaying last 5 rows of database 

# In[7]:


print(data.tail(5))


# # Dimension of Database

# In[8]:


print(data.shape)


# # Detailed Information of dataset 

# In[9]:


data.info()


# # Displaying Column names

# In[11]:


column_names = list(data.columns.values)
print(column_names)


# # Renaming column names 

# In[15]:


data.rename(columns={'Age':'AGE', 'Chol':'Cholestrol', 'AHD':'ahd'}, inplace = True)
column_names = list(data.columns.values)
print(column_names)


# In[16]:


data.head()


# # Null Values in each column 

# In[7]:


count_null = data.isna().sum().sum
print(count_null)


# # Datatype of each attribute of Dataset

# In[8]:


data.dtypes


# # Mapping Yes/No to 1/0 in AHD column

# In[29]:


data['AHD'] = data['AHD'].map({'Yes': 1, 'No': 0})
print(data)


# # Dropping unnamed column

# In[30]:


data = data.drop(columns='Unnamed: 0')
print(data)


# # Splitting Dataset in Training and Testing

# In[44]:


from sklearn.model_selection import train_test_split
x = data[['Age', 'Sex', 'ChestPain', 'RestBP', 'Chol']]
y = data['AHD']
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2)


# # Checking newly split dataset

# In[41]:


x_train.shape


# In[42]:


x_test.shape

