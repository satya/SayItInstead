import asyncore, os, re, sgmllib, socket, string, subprocess, sys, time, xml.dom.minidom, 
from enthought import guitest

# TODO Add working definitions instead of stubs and remove hard-coded stuff

julius_home=os.getenv("JULIUS_HOME", "/usr/local/include/julius")
julius_model=julius_home + "/model/julius.jconf"
julius_port=10500
julius_cmd="julius -input mic  -smpFreq 48000 -nlr /home/skomarag/Desktop/LM/words/bigram_model -nrl /home/skomarag/Desktop/LM2/words/reverse_trigram_model -h /home/skomarag/voxforge/manual/hmm9/hmmdefs  -hlist /home/skomarag/voxforge/manual/monophones1 -v /home/skomarag/voxforge/manual/dict -C "+julius_model+" -module "+str(julius_port)

#Client Definition
class juli_client(asyncore.dispatcher):
    def __init__(self, host="127.0.0.1", port=julius_port):
        asyncore.dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.bufsize=8192
        self.connect((host, port))
        self.xmlstr=''

    def handle_connect(self):
        pass

    def handle_close(self):
        self.close()

    def on_startproc(self, node):
        pass

    def on_startrecog(self, node):
        pass

    def handle_write(self):
        pass

    def on_endrecog(self, node):
        pass

    def on_input(self, node):
        pass

    def on_inputparam(self, node):
        pass

    def on_recogout(self, node):
        w = guitest.GetInputFocus()
        for shypo in node.getElementsByTagName("SHYPO"):
            for whypo in node.getElementsByTagName("WHYPO"):
                 word = whypo.getAttribute("WORD")
                 for char in list(word):
                    guitest.SendKeys(guitest.QuoteStringForSendKeys(char))
                    time.sleep(0.05)                

    def on_recogfail(self, node):
        pass

    def on_unknown(self, node):
        print "Unable to recognize: "+node.localName
        pass

    def handle_xml(self):
        #Sanitize XML
        self.xmlstr=re.sub('/>',' />',self.xmlstr)
        self.xmlstr=re.sub('<s>','&lt;s&gt;',self.xmlstr)
        self.xmlstr=re.sub('</s>','&lt;/s&gt;',self.xmlstr)
        try:
            self.julidom = xml.dom.minidom.parseString(self.xmlstr)
            for node in self.julidom.childNodes:
                if node.localName == "STARTPROC":
                   self.on_startproc(node)
                elif node.localName == "STARTRECOG":
                   self.on_startrecog(node)
                elif node.localName == "ENDRECOG":
                   self.on_endrecog(node)
                elif node.localName == "INPUT":
                   self.on_input(node)
                elif node.localName == "INPUTPARAM":
                   self.on_inputparam(node)
                elif node.localName == "RECOGOUT":
                   self.on_recogout(node)
                elif node.localName == "RECOGFAIL":
                   self.on_recogfail(node)
                else:
                   self.on_unknown(node)
        except:
            print "Error in: {"+self.xmlstr+"}";
            print sys.exc_info()
 
    def handle_read(self):
        self.buffer=self.recv(self.bufsize)
        self.messages= string.split(self.buffer, "\n")
        for message in self.messages:
            if message == '.':
                if self.xmlstr != '':
                   self.handle_xml()
                self.xmlstr=''
            elif message == '':
                pass
            else:
                self.xmlstr+=message

#Run Process
juli_proc = subprocess.Popen([julius_cmd], shell=True, stdin=subprocess.PIPE, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
(child_stdin, child_stderr, child_stdout) = (juli_proc.stdin, juli_proc.stderr, juli_proc.stdout)

#Wait and Connect
time.sleep(10)

#Run Client
juli_cli=juli_client()
asyncore.loop()

#Close Process
juli_proc.wait()
