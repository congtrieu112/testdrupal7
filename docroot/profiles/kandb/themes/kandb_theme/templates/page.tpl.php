<?php
$path_img = kandb_theme_get_path('test_assets', 'kandb_theme');
$logo_svg = kandb_theme_get_path('assets', 'kandb_theme') . '/images/logo-Kaufman-Broad.svg';
?>
<div class="main-wrapper">
    <!-- [siteHeader] start-->
    <aside class="hide-for-large-up pushy pushy-left">
        <ul class="pushy__menu">
            <li class="pushy__menu__item"><a href="#">Nos offres</a></li>
            <li class="pushy__menu__item"><a href="#">Nos services</a></li>
            <li class="pushy__menu__item"><a href="#">Nos conseils</a></li>
            <li class="pushy__menu__item"><a href="#">Le groupe</a></li>
        </ul>
    </aside>
    <div class="sticky contain-to-grid">
        <header data-topbar role="banner" class="header">
            <button class="hide-for-large-up menu-btn"><span>Ouvrir le menu</span></button>
            <ul class="header__title title-area show-for-large-up">
                <li class="name"><a href="index.html" title="K&amp;B homepage" class="title-area__link"><img src="<?php print $logo_svg; ?>" alt="Kaufman&amp;Board"></a></li>
                <li role="search" class="has-form hidden">
                    <form action="#" method="post" class="row collapse">
                        <div class="large-4 small-3 columns">
                            <button type="submit" class="button expand">Ok</button>
                        </div>
                        <div class="large-8 small-9 columns">
                            <input type="text" placeholder="Ville, programme, bien...">
                        </div>
                    </form>
                </li>
            </ul>
            <nav aria-label="Menu principal" class="header__menu show-for-large-up right">
                <ul class="main-menu">
                    <li class="main-menu__item"><a href="#">Nos offres</a></li>
                    <li class="main-menu__item"><a href="#">Nos services</a></li>
                    <li class="main-menu__item"><a href="#">Nos conseils</a></li>
                    <li class="main-menu__item"><a href="#">Le groupe</a></li>
                </ul>
                <!-- [buttonDropdown] start-->
                <button data-dropdown="accountDropdown" aria-controls="accountDropdown" aria-expanded="false" class="btn-primary btn-rounded header__btn">Mon compte<span class="icon icon-expand"></span>
                </button>
                <ul id="accountDropdown" data-dropdown-content="data-dropdown-content" role="menu" aria-hidden="true" tabindex="-1" class="f-dropdown">
                    <li><a href="#">Mon espace</a></li>
                    <li><a href="#">Mes informations</a></li>
                    <li><a href="#">Déconnexion</a></li>
                </ul>
                <!-- [buttonDropdown] start-->
            </nav>
        </header>
    </div>
    <div class="site-overlay"></div>
    <!-- [siteHeader] end-->
    <main id="container">
        <?php print render($page['content']); ?>
    </main>
</div>