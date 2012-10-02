WebItemDelegate is a class which provides a way to use WebKit
to render interactive items in Qt item views.

The aim is to combine the ease of creating rich content that HTML/CSS/JS provide
with the native look and behavior of Qt's item view widgets.

For each visible model index in the view, WebItemDelegate creates a DOM
element in a hidden web page.  The DOM element is sized to match
the visual area of the item and drawn as the item's content.

Input events to the item view are translated to corresponding
input events on the web page, allowing items to contain links,
form controls and other interactive content.



