# TicTacToe-GUI-CPP
<p>A TicTacToe game that is a GUI Application in C++...</p>

# How to WxWidget For project!
## For Windows 

<pre>
<h3>Using Mingw-W64</h3>
First Download WxWidget header files, development files and Release DLLs from link <a href="https://www.wxwidgets.org/downloads/">https://www.wxwidgets.org/downloads/<a> <br>
Then Extract in WxWdidget folder that we will use as main WxWdidget build folder. <br>
Change the compileinwindows.bat file as per location of WxWdidget folder and DAB! double click on compileinwindows.bat file to compile using g++ compiler. <br>
Note: <b>If want compile using Visual Studio and MSCompiler then follow WxWidget Docs...</b> 
</pre>

## For Unix based system like Ubuntu 
<pre>
First Download WxWidget Source code to build WxWidget from link <a href="https://www.wxwidgets.org/downloads/">https://www.wxwidgets.org/downloads/<a> <br>
Then Extract the Zip file and go inside the extracted folder.<br>
Note: <b>You need to install GTK development libary before any futhur process, if not already installed. for installing it Run </b><code>sudo apt install libgtk-3-dev</code><br>
<code>cd ~/wx/wxwdiget-3.1.3</code><br>
<code>mkdir gtk-build/</code><br>
<code>cd gtk-build</code><br>
<code>../configure</code><br>
<code>make -j3</code><br>
<code>make install</code><br>
<code>ldconfig</code><br>
Note: <b>If you get any permission error then run following commands using sudo.</b>
Finally you can Run: <b>make</b> inside the repo to build the project..
</pre>


