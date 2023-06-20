# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "Home GitinspectorGUI"
copyright = "2023, Adam Waldenberg and GitinspectorGUI Team"
author = "GitinspectorGUI Team"
version = "0.1"
release = "0.1alpha"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["sphinx_rtd_theme"]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

# The master toctree document.
# root_doc = 'index'
root_doc = "index"

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]

html_css_files = ["page-width.css", "wide-table-wrap.css"]

# Do not include the sources as part of the html output.
# This also means that there will be no link to the sources on the top line
# of each web page.
html_copy_source = False
