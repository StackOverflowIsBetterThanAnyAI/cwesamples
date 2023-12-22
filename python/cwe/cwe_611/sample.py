from lxml import etree

def process_xml(xml_data):
    try:
        # Analyse du document XML en utilisant le parseur sécurisé de lxml
        parser = etree.XMLParser(resolve_entities=True)
        root = etree.fromstring(xml_data, parser=parser)

        # Récupération de l'élément 'name' du document XML
        name = root.find('name').text

        return f"Hello, {name}!"
    except etree.XMLSyntaxError as e:
        return f"Erreur d'analyse XML : {e}"

# Exemple d'utilisation avec une entité externe
xml_input = """
<!DOCTYPE data [
  <!ENTITY xxe SYSTEM "file:///etc/passwd" >
]>
<data>
    <name>&xxe;</name>
</data>
"""

result = process_xml(xml_input)
print(result)