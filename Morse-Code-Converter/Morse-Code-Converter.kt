import java.awt.Font
import java.awt.GridBagConstraints
import java.awt.GridBagLayout
import java.awt.GridLayout
import java.util.*
import javax.swing.*
import javax.swing.border.EmptyBorder

fun makeMorseCode(str:String):String{
    if(str == "")   return ""

    @Suppress("DEPRECATION") val given = str.lowercase(Locale.getDefault()).strip()

    val morseCodeLetter = listOf("._","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._.."
        ,"__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..")
    val morseCodeNumber = listOf("_____",".____","..___","...__","...._",".....","_....","__...","___..","____.")
    val morseCodeChar =  hashMapOf(',' to ".._..",'.' to "._._.",'?' to "..__..",';' to "_._._",':' to "___...",
        '/' to "_.._.",'-' to "_...._",'_' to "..__._",'\'' to ".____.")
    var morseName = ""
    for (i in given){
        morseName += if(i.isLetter()) morseCodeLetter[i-'a']+" "
        else if(i.isDigit()) morseCodeNumber[i-'0']+" "
        else if(i != ' ') morseCodeChar[i]+" "
        else " / "
    }

    @Suppress("DEPRECATION")
    return morseName.strip()
}

fun wordToCode(){
    val frame  = JPanel()

    val iframe = JFrame("Word to Code")
    iframe.defaultCloseOperation = JFrame.EXIT_ON_CLOSE

    val label1 = JLabel("Enter Word : ")
    label1.font = Font("Ariel",Font.BOLD,20)
    frame.add(label1)

    val inputs = JTextField(20)
    frame.add(inputs)
    frame.add(JLabel(""))

    val button = JButton("Convert")
    GridBagConstraints().gridx = 1
    GridBagConstraints().gridy = 0
    frame.add(button)
    frame.add(JLabel(""))

    val end = JButton("Home")
    GridBagConstraints().gridx = 1
    GridBagConstraints().gridy = 1
    frame.add(end)
    frame.add(JLabel(""))
    end.addActionListener {
        iframe.dispose()
        mainPage()
    }
    val code = JLabel("Morse code -->")
    code.font = Font("Ariel",Font.ITALIC,20)
    frame.add(code)

    val label2 = JTextField("")
    frame.add(label2)

    button.addActionListener{
        val text = makeMorseCode(inputs.text.toString())
        if(text=="")    label2.text = "Enter Something ......"
        else label2.text = "$text "
    }

    frame.layout = GridLayout(0,1)
    iframe.add(frame)
    iframe.setSize(700,400)
    iframe.layout = GridBagLayout()
    iframe.isVisible = true
}

fun makeWord(str:String):String{
    if(str=="") return ""

    val code= str.lowercase(Locale.getDefault())
    var result = ""
    val givenCharacters = code.split(" ")

    val morseCharacters = hashMapOf("._" to "A","_..." to "B","_._." to "C","_.." to "D","." to "E",
        ".._." to "F","__." to "G","...." to "H",".." to "I",".___" to "J","_._" to "K","._.." to "L"
        ,"__" to "M","_." to "N","___" to "O",".__." to "P","__._" to "Q","._." to "R","..." to "S",
        "_" to "T",".._" to "U","..._" to "V",".__" to "W","_.._" to "X","_.__" to "Y","__.." to "Z",
        "_____" to '0',".____" to "1","..___" to "2","...__" to "3","...._" to "4","....." to "5",
        "_...." to "6","__..." to "7","___.." to "8","____." to "9",".._.." to ",","._._." to ".",
        "..__.." to "?","_._._" to ";","___..." to ":","_.._." to "/","_...._" to "-","..__._" to "_",
        ".____." to "'")
    for( i in givenCharacters){
        if(morseCharacters[i] == null) result += " "
        else result += morseCharacters[i]
        println(result)
    }
    return result
}

fun codeToWord(){
    val frame = JPanel()

    val iframe = JFrame("Code to Word")

    iframe.defaultCloseOperation = JFrame.EXIT_ON_CLOSE

    val label1 = JLabel("Enter Code : ")
    label1.font = Font("Ariel",Font.BOLD,20)
    frame.add(label1)

    val label2 = JTextField("")

    val input = JTextField(20)
    frame.add(input)
    frame.add(JLabel(""))

    val button = JButton("Convert")
    frame.add(button)
    button.addActionListener {
        val text  = makeWord(input.text.toString())
        if(text == "")     label2.text = "Enter Something...."
        else    label2.text = "$text "
    }
    frame.add(JLabel(""))
    val end = JButton("Home")
    frame.add(end)
    frame.add(JLabel(""))
    end.addActionListener {
        iframe.dispose()
        mainPage()
    }
    val display = JLabel("Word --> ")
    display.font = Font("Ariel",Font.BOLD,20)
    frame.add(display)
    frame.add(label2)

    frame.layout = GridLayout(0,1)
    iframe.add(frame)
    iframe.setSize(700,400)
    iframe.layout = GridBagLayout()
    iframe.isVisible = true

}

fun mainPage(){

    val jFrame = JFrame("Code Converter : ")
    jFrame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
    jFrame.setSize(700,400)

    val mainFrame = JPanel()
    val title = JLabel("Morse Code Converter ....")
    val label = JLabel("Choose the One to Convert : \n\n")
    label.border = EmptyBorder(10,40,10,20)
    title.border = EmptyBorder(10,40,25,20)

    title.font = Font("calibre",Font.ITALIC,35)
    label.font = Font("calibre",Font.ITALIC,20)
    mainFrame.add(title)
    mainFrame.add(label)

    val button1 = JButton("Word to Code")
    mainFrame.add(button1)
    button1.addActionListener {
        jFrame.dispose()
        SwingUtilities.invokeLater(::wordToCode) }

    val button2 = JButton("Code to Word")
    mainFrame.add(button2)
    button2.addActionListener {
        jFrame.dispose()
        SwingUtilities.invokeLater(::codeToWord) }

    mainFrame.layout = GridLayout(0,1)
    jFrame.add(mainFrame)
    jFrame.layout = GridBagLayout()
    jFrame.isVisible = true
}

fun main(){
    println("\n\tMorse Code Converter.....\n\n")
    mainPage()
}