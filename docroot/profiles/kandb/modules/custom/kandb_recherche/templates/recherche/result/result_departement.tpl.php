<?php echo t('Nous n\'avons pas trouvé de résultats correspondant à votre recherche.'); ?><br/>
<?php echo t('Trouvez votre logement dans le département de votre choix :'); ?><br/>
<?php foreach($departement as $dpt): ?>
    <a href="<?php echo $dpt['link']; ?>" ><?php echo $dpt['name']; ?></a><br/>
<?php endforeach; ?>