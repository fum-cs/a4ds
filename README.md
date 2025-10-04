![](img/banner.png)

# Welcome to *Algorithms for Data Science* Course website

This courses covers the fundamental algorithms in data mining and machine learning; form the basis of data science, utilizing automated methods to analyze patterns and models for all kinds of data in applications ranging from scientific discovery to business analytics.

# Course Staff  

## Instructors  

<table style="width:100%;">  
  <tr>  
    <td style="width:20%;">  
      <img src="images/M-Amintoosi.jpg" alt="Mahmood Amintoosi" style="width:100px;height:auto;">  
    </td>  
    <td>  
      <strong><a href="https://mamintoosi.github.io/">Mahmood Amintoosi</a></strong><br>  
      Email: m.amintoosi AT um.ac.ir
    </td>  
  </tr>  
</table>  

---  

## Teaching Assistants  

<table style="width:100%;">  
  <tr>  
    <td style="width:20%;">  
      <img src="images/H-Mehr.jpg" alt="Hoda MehrBagherpour" style="width:100px;height:auto;">  
    </td>  
    <td>  
      <strong><a href="https://github.com/HodaMehr2000">Hoda MehrBagherpour</a></strong><br>  
      Email: mehrbagherpour AT mail.um.ac.ir  
    </td>  
  </tr>  
</table>


- [Course Jupyter Book](https://fum-cs.github.io/a4ds/)

---

I should mention that the original material was from [Jake VanderPlas's DS book github](https://github.com/jakevdp/PythonDataScienceHandbook/). I have modified his contents to suit my own needs and preferences. I would like to thank him for his great work and generosity.

## Build

In notebooks folder:
- jupyter-book build ./
- copy ..\require.js _build\html\
- copy *.jpg _build\html\_images\
- ghp-import -n -p -f ./_build/html
- jupyter-book build --builder pdflatex ./
