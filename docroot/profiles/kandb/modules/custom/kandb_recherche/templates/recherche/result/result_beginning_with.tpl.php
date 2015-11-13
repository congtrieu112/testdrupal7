<?php echo t('Nous n\'avons pas trouvé de résultats correspondant à votre recherche.'); ?><br/>
<?php echo t('Recherchiez-vous :'); ?><br/><br/>

<?php if(!empty($ville)): ?>
  <?php echo t('Une ville ?'); ?><br/>
  <?php foreach($ville as $object): ?>
    <a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a><br/>
  <?php endforeach; ?>
  <br/>
<?php endif; ?>

<?php if(!empty($departement)): ?>
  <?php echo t('Un département ?'); ?><br/>
  <?php foreach($departement as $object): ?>
    <a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a><br/>
  <?php endforeach; ?>
  <br/>
<?php endif; ?>

<?php if(!empty($region)): ?>
  <?php echo t('Une région ?'); ?><br/>
  <?php foreach($region as $object): ?>
    <a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a><br/>
  <?php endforeach; ?>
  <br/>
<?php endif; ?>

<?php if(!empty($programme)): ?>
  <?php echo t('Un programme ?'); ?><br/>
  <?php foreach($programme as $object): ?>
    <a href="<?php echo $object['link']; ?>" ><?php echo $object['name']; ?></a><br/>
  <?php endforeach; ?>
  <br/>
<?php endif; ?>
